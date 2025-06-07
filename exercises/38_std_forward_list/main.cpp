#include "../exercise.h"
#include <forward_list>

// READ: `std::forward_list` <https://zh.cppreference.com/w/cpp/container/forward_list>

int main(int argc, char **argv) {
    // TODO: 为下列 ASSERT 填写正确的值
    {
        std::forward_list<int> fl = {1, 2, 3};
        fl.push_front(0);

        // TODO: 为下面的 ASSERT 填写正确的表达式
        ASSERT(? == 0, "Front element should be 0");

        fl.pop_front();
        ASSERT(fl.front() == ?, "Front element should now be ?");
    }
    {
        std::forward_list<int> fl = {1, 3, 5};
        auto it = fl.before_begin();
        fl.insert_after(it, 0);

        ASSERT(fl.front() == ?, "Front element should be ?");

        // TODO: 为下面的 ASSERT 填写正确的表达式
        fl.erase_after(?);
        ASSERT(*std::next(fl.begin()) == 3, "Second element should be 3");
    }
    {
        std::forward_list<int> fl = {10, 20, 30};
        int sum = 0;
        for (const auto &val : fl) {
            sum += val;
        }
        ASSERT(sum == ?, "Sum of elements should be ?");
    }
    {
        // 合并与排序
        std::forward_list<int> fl1 = {3, 5, 7};
        std::forward_list<int> fl2 = {2, 4, 6};

        fl1.merge(fl2);

        // TODO: 为 ? 填写正确的值
        int expected[] = {?};
        int index = 0;
        for (int val : fl1) {
            ASSERT(val == expected[index++], "Merged list should be sorted");
        }
        ASSERT(?, "填入 fl2.empty() 或者 !fl2.empty()");
    }
    {
        // 拼接操作
        std::forward_list<int> fl1 = {1, 2, 3, 4};
        std::forward_list<int> fl2 = {10, 20};

        auto it = fl1.begin();
        ++it;
        fl1.splice_after(it, fl2, fl2.before_begin(), fl2.end());

        // TODO: 为 ? 填写正确的值
        int expected[] = {?};
        int index = 0;
        for (int val : fl1) {
            ASSERT(val == expected[index++], "Splice_after should insert elements correctly");
        }
        ASSERT(?, "填入 fl2.empty() 或者 !fl2.empty()");
    }
    {
        // 比较运算符测试
        std::forward_list<int> fl1 = {1, 2, 3};
        std::forward_list<int> fl2 = {1, 2, 3};
        std::forward_list<int> fl3 = {1, 2, 4};

        ASSERT(fl1 ? fl2, "填入正确的比较运算符，== 或 != 或 < 或 >");
        ASSERT(fl1 ? fl3, "填入正确的比较运算符，== 或 != 或 < 或 >");
        ASSERT(fl1 ? fl3, "填入正确的比较运算符，== 或 != 或 < 或 >");
    }
    return 0;
}
