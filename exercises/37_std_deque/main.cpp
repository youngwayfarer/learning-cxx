#include "../exercise.h"
#include <deque>

// READ: `std::deque` <https://zh.cppreference.com/w/cpp/container/deque>

int main(int argc, char **argv) {
    {
        // 基本使用
        std::deque<int> dq = {1, 2, 3};
        dq.push_front(0);
        dq.push_back(4);

        ASSERT(dq.front() == 0, "Front element should be 0");
        ASSERT(dq.back() == 4, "Back element should be 4");

        dq.pop_front();
        dq.pop_back();

        ASSERT(dq.size() == 3, "Deque size should be 3 after popping");
        ASSERT(dq[0] == 1 && dq[1] == 2 && dq[2] == 3, "Deque elements should be 1, 2, 3");
    }
    {
        // 插入与删除
        std::deque<std::string> dq;
        dq.emplace_back("Hello");
        dq.emplace_front("World");

        ASSERT(dq.front() == "World", "Front element should be 'World'");
        ASSERT(dq.back() == "Hello", "Back element should be 'Hello'");

        dq.erase(dq.begin());
        ASSERT(dq.size() == 1, "Deque size should be 1 after erase");
        ASSERT(dq.front() == "Hello", "Remaining element should be 'Hello'");
    }
    {
        // 遍历
        std::deque<int> dq = {10, 20, 30};
        int sum = 0;
        for (const auto &val : dq) {
            sum += val;
        }
        ASSERT(sum == 60, "Sum of elements should be 60");
    }
    return 0;
}
