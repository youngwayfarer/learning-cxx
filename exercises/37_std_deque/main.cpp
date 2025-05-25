#include "../exercise.h"
#include <deque>

// READ: `std::deque` <https://zh.cppreference.com/w/cpp/container/deque>

int main(int argc, char **argv) {
    // TODO: 为下列 ASSERT 填写正确的值
    {
        std::deque<int> dq = {1, 2, 3};
        // TODO: 使用 `push_front` 和 `push_back` 添加正确元素
        dq.push_front(?);
        dq.push_back(?);

        ASSERT(dq.front() == 0, "Front element should be 0");
        ASSERT(dq.back() == 4, "Back element should be 4");

        dq.pop_front();
        dq.pop_back();

        ASSERT(dq.size() == ?, "Deque size should be ? after popping");
        ASSERT(dq[0] == ? && dq[1] == ? && dq[2] == ?, "Deque elements should be ?");
    }
    {
        std::deque<std::string> dq;
        // TODO: 使用 `emplace_back` 和 `emplace_front` 添加正确元素
        dq.emplace_back(?);
        dq.emplace_front(?);

        ASSERT(dq.front() == "World", "Front element should be 'World'");
        ASSERT(dq.back() == "Hello", "Back element should be 'Hello'");

        // TODO: 使用 `erase` 删除正确元素
        dq.erase(?);
        ASSERT(dq.size() == 1, "Deque size should be 1 after erase");
        ASSERT(dq.front() == "Hello", "Remaining element should be 'Hello'");
    }
    {
        std::deque<int> dq = {10, 20, 30};
        int sum = 0;
        for (const auto &val : dq) {
            sum += val;
        }
        ASSERT(sum == ?, "Sum of elements should be ?");
    }
    return 0;
}
