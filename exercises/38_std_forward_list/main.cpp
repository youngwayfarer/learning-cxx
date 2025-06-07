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
    {
        // 合并与排序
        std::forward_list<int> fl1 = {3, 5, 7};
        std::forward_list<int> fl2 = {2, 4, 6};

        fl1.merge(fl2);// 合并后应为 {2, 3, 4, 5, 6, 7}

        int expected[] = {2, 3, 4, 5, 6, 7};
        int index = 0;
        for (int val : fl1) {
            ASSERT(val == expected[index++], "Merged list should be sorted");
        }
        ASSERT(fl2.empty(), "Merged list should be empty after merge");
    }
    {
        // 拼接操作
        std::forward_list<int> fl1 = {1, 2, 3, 4};
        std::forward_list<int> fl2 = {10, 20};

        auto it = fl1.begin();
        ++it;// 指向第二个元素
        fl1.splice_after(it, fl2, fl2.before_begin(), fl2.end());

        // fl1 应为 {1, 2, 10, 20, 3, 4}
        int expected[] = {1, 2, 10, 20, 3, 4};
        int index = 0;
        for (int val : fl1) {
            ASSERT(val == expected[index++], "Splice_after should insert elements correctly");
        }
        ASSERT(fl2.empty(), "Spliced list should be empty after operation");
    }
    {
        // 比较运算符测试
        std::forward_list<int> fl1 = {1, 2, 3};
        std::forward_list<int> fl2 = {1, 2, 3};
        std::forward_list<int> fl3 = {1, 2, 4};

        ASSERT(fl1 == fl2, "Equal lists should compare equal");
        ASSERT(fl1 != fl3, "Different lists should compare unequal");
        ASSERT(fl1 < fl3, "Lexicographical comparison should work");
    }
    return 0;
}
