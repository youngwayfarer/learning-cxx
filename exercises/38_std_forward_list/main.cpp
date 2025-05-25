#include "../exercise.h"
#include <forward_list>

// READ: `std::forward_list` <https://zh.cppreference.com/w/cpp/container/forward_list>

int main(int argc, char **argv) {
    {
        // 基本使用
        std::forward_list<int> fl = {1, 2, 3};
        fl.push_front(0);

        ASSERT(fl.front() == 0, "Front element should be 0");

        fl.pop_front();
        ASSERT(fl.front() == 1, "Front element should now be 1");
    }
    {
        // 插入与删除
        std::forward_list<int> fl = {1, 3, 5};
        auto it = fl.before_begin();
        fl.insert_after(it, 0);

        ASSERT(fl.front() == 0, "Front element should be 0");

        it = fl.begin();
        fl.erase_after(it);
        ASSERT(*std::next(fl.begin()) == 3, "Second element should be 3");
    }
    {
        // 遍历
        std::forward_list<int> fl = {10, 20, 30};
        int sum = 0;
        for (const auto &val : fl) {
            sum += val;
        }
        ASSERT(sum == 60, "Sum of elements should be 60");
    }
    return 0;
}
