#include "../exercise.h"
#include <mutex>
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
    return 0;
}
