#include "../exercise.h"
#include <optional>
#include <vector>

// READ: `optional` <https://zh.cppreference.com/w/cpp/utility/optional>

std::optional<int> find_even(const std::vector<int> &nums) {
    for (int n : nums) {
        if (n % 2 == 0) {
            return n;
        }
    }
    return std::nullopt;
}

int main(int argc, char **argv) {
    // TODO: 为下列 ASSERT 中填写正确的值
    {
        std::vector<int> nums{1, 3, 5, 7, 8};
        auto result = find_even(nums);
        ASSERT(?, "填入 result.has_value() 或 !result.has_value()");
        ASSERT(result.value() == ?, "The even number should be ?");

        std::vector<int> odd_nums{1, 3, 5, 7};
        auto no_even = find_even(odd_nums);
        // TODO: 为 ? 填写正确的值
        int default_value = no_even.value_or(?);
        ASSERT(default_value == -1, "Default value should be -1 when no even number is found");
    }
    {
        std::optional<int> opt_value;
        ASSERT(?, "填入 opt_value.has_value() 或 !opt_value.has_value()");
        opt_value.emplace(42);
        ASSERT(?, "填入 opt_value.has_value() 或 !opt_value.has_value()");
        ASSERT(opt_value.value() == ?, "The value should be ?");

        std::optional<int> empty_opt;
        ASSERT(empty_opt ? std::nullopt, "填入 == 或 !=");
        ASSERT(opt_value ? std::nullopt, "填入 == 或 !=");

        opt_value.reset();
        ASSERT(?, "填入 opt_value.has_value() 或 !opt_value.has_value()");
        ASSERT(opt_value ? std::nullopt, "填入 == 或 !=y");
    }
    return 0;
}