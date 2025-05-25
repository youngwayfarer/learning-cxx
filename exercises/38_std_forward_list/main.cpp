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
    return 0;
}
