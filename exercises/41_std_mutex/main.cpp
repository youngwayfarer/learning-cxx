#include "../exercise.h"
#include <condition_variable>// 修复：缺少 std::condition_variable
#include <mutex>
#include <mutex>// 修复：缺少 std::mutex
#include <queue>// 修复：缺少 std::queue
#include <thread>
#include <vector>

// READ: `std::mutex` <https://zh.cppreference.com/w/cpp/thread/mutex>

std::mutex mtx;
int counter = 0;

void increment_counter(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        //TODO: 使用 std::lock_guard 保护对 counter 的访问
        ?
        ++counter;
    }
}

int main(int argc, char **argv) {
    // TODO: 为下列 ASSERT 填写正确的值
    {
        // 基本使用
        std::thread t1(increment_counter, 1000);
        std::thread t2(increment_counter, 1000);

        t1.join();
        t2.join();

        ASSERT(counter == ?, "Counter should be ? after both threads finish");
    }
    {
        std::vector<int> shared_data;
        auto append_data = [&shared_data](int value) {
            std::lock_guard<std::mutex> lock(mtx);
            shared_data.push_back(value);
        };

        std::thread t1(append_data, 1);
        std::thread t2(append_data, 2);

        t1.join();
        t2.join();

        ASSERT(shared_data.size() == ?, "Shared data should contain ? elements");
        ASSERT(?, "判断 shared_data 中的值，如(shared_data[0] == 1 && shared_data[1] == 2)");
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
                // TODO: 为消费者进程设置正确的行为，注意：循环退出条件

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
            // TODO: 为 fork2 加锁
            
            ++eaten;
        });

        std::thread philosopher2([&]() {
            std::unique_lock<std::mutex> lock1(fork2, std::defer_lock);
            std::unique_lock<std::mutex> lock2(fork1, std::defer_lock);
            // TODO: 原子操作为 fork1、 fork2 加锁
            // 思考为什么这样可以避免死锁

            ++eaten;
        });

        philosopher1.join();
        philosopher2.join();

        ASSERT(eaten == ?, "Both philosophers should have eaten");
    }


    return 0;
}
