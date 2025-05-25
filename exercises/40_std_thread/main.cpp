#include "../exercise.h"
#include <atomic>
#include <chrono>
#include <future>
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
    // TODO: 为下列 ASSERT 填写正确的值
    {
        std::thread t(print_message, "Hello from thread!");
        t.join();
    }
    {
        std::vector<int> nums(100, 1);
        int result1 = 0, result2 = 0;

        // TODO: 为下面填写正确的值
        std::thread t1(accumulate_range, std::ref(nums), 0, ?, std::ref(result1));
        std::thread t2(accumulate_range, std::ref(nums), ?, 100, std::ref(result2));

        t1.join();
        t2.join();

        ASSERT(result1 == 50, "First half sum should be 50");
        ASSERT(result2 == 50, "Second half sum should be 50");
        ASSERT(result1 + result2 == 100, "Total sum should be 100");
    }
    {
        int counter = 0;
        // TODO: 为下面线程填写正确的入口匿名函数，修改 counter 的值以通过测试
        std::thread t(?);
        t.join();
        ASSERT(counter == 10, "Counter should be 10 after thread execution");
    }
    {
        std::thread t(detached_task);
        t.detach();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Main thread completed after 2 seconds." << std::endl;
    }
    {
        std::thread t([]() {
            std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
        });
        t.join();
    }
    {
        std::atomic<int> counter{0};
        const int iterations = 1000;

        auto increment = [&counter, iterations]() {
            for (int i = 0; i < iterations; ++i) {
                counter.fetch_add(1, std::memory_order_relaxed);
            }
        };

        std::vector<std::thread> threads;
        for (int i = 0; i < 10; ++i) {
            // TODO: 为每个线程填写正确的入口匿名函数，修改 counter 的值以通过测试

        }

        for (auto &t : threads) {
            t.join();
        }

        ASSERT(counter == ?, "Atomic counter should be ?");
    }
    {
        std::promise<int> p;
        std::future<int> f = p.get_future();

        // TODO: 填写需要捕获的变量
        std::thread t([?]() {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            p.set_value_at_thread_exit(42);
        });

        ASSERT(f.get() == ?, "Future should get value ? from promise");

        t.join();
    }
    {
        thread_local int thread_local_counter = 0;

        auto inc_local = []() {
            for (int i = 0; i < 1000; ++i) {
                ++thread_local_counter;
            }
        };

        std::thread t1(inc_local);
        std::thread t2(inc_local);

        t1.join();
        t2.join();

        ASSERT(thread_local_counter == ?, "Thread local counter in main thread should be ?");
    }
    return 0;
}
