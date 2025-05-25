#include "../exercise.h"
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

// READ: `std::mutex` <https://zh.cppreference.com/w/cpp/thread/mutex>

std::mutex mtx;
int counter = 0;

void increment_counter(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

int main(int argc, char **argv) {
    {
        // 基本使用
        std::thread t1(increment_counter, 1000);
        std::thread t2(increment_counter, 1000);

        t1.join();
        t2.join();

        ASSERT(counter == 2000, "Counter should be 2000 after both threads finish");
    }
    {
        // 多线程安全访问
        std::vector<int> shared_data;
        auto append_data = [&shared_data](int value) {
            std::lock_guard<std::mutex> lock(mtx);
            shared_data.push_back(value);
        };

        std::thread t1(append_data, 1);
        std::thread t2(append_data, 2);

        t1.join();
        t2.join();

        ASSERT(shared_data.size() == 2, "Shared data should contain 2 elements");
        ASSERT((shared_data[0] == 1 && shared_data[1] == 2) ||
                   (shared_data[0] == 2 && shared_data[1] == 1),
               "Shared data should contain values 1 and 2 in any order");
    }
    {
        std::queue<int> data_queue;
        std::mutex mtx;
        std::condition_variable cv;
        bool done = false;
        int received = 0;

        std::thread producer([&]() {
            for (int i = 1; i <= 5; ++i) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::lock_guard<std::mutex> lock(mtx);
                data_queue.push(i);
                cv.notify_one();
            }
            done = true;
            cv.notify_one();
        });

        std::thread consumer([&]() {
            while (true) {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&] { return !data_queue.empty() || done; });
                if (done && data_queue.empty()) break;
                received += data_queue.front();
                data_queue.pop();
            }
        });

        producer.join();
        consumer.join();

        ASSERT(received == 15, "Consumer should receive sum 1+2+3+4+5=15");
    }
    {
        std::mutex fork1, fork2;
        int eaten = 0;

        std::thread philosopher1([&]() {
            std::lock_guard<std::mutex> lock1(fork1);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::lock_guard<std::mutex> lock2(fork2);
            ++eaten;
        });

        std::thread philosopher2([&]() {
            // 使用std::lock避免死锁
            std::unique_lock<std::mutex> lock1(fork2, std::defer_lock);
            std::unique_lock<std::mutex> lock2(fork1, std::defer_lock);
            std::lock(lock1, lock2);
            ++eaten;
        });

        philosopher1.join();
        philosopher2.join();

        ASSERT(eaten == 2, "Both philosophers should have eaten");
    }
    return 0;
}
