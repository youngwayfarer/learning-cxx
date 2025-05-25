#include "../exercise.h"
#include <chrono>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

// READ: `std::thread` <https://zh.cppreference.com/w/cpp/thread/thread>

void print_message(const std::string &message) {
    std::cout << message << std::endl;
}

void accumulate_range(const std::vector<int> &nums, int start, int end, int &result) {
    result = std::accumulate(nums.begin() + start, nums.begin() + end, 0);
}

void detached_task() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Detached thread completed after 1 second." << std::endl;
}

int main(int argc, char **argv) {
    {
        // 基本使用
        std::thread t(print_message, "Hello from thread!");
        t.join();
    }
    {
        // 多线程计算
        std::vector<int> nums(100, 1);
        int result1 = 0, result2 = 0;

        std::thread t1(accumulate_range, std::ref(nums), 0, 50, std::ref(result1));
        std::thread t2(accumulate_range, std::ref(nums), 50, 100, std::ref(result2));

        t1.join();
        t2.join();

        ASSERT(result1 == 50, "First half sum should be 50");
        ASSERT(result2 == 50, "Second half sum should be 50");
        ASSERT(result1 + result2 == 100, "Total sum should be 100");
    }
    {
        // Lambda 表达式线程
        int counter = 0;
        std::thread t([&counter]() {
            for (int i = 0; i < 10; ++i) {
                ++counter;
            }
        });
        t.join();
        ASSERT(counter == 10, "Counter should be 10 after thread execution");
    }
    {
        // 分离线程 (detach)
        std::thread t(detached_task);
        t.detach();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Main thread completed after 2 seconds." << std::endl;
    }
    {
        // 获取线程 ID
        std::thread t([]() {
            std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
        });
        t.join();
    }
    return 0;
}
