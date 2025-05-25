#include "../exercise.h"
#include <iostream>
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
    {
        // 基本使用
        std::vector<int> nums{1, 3, 5, 7, 8};
        auto result = find_even(nums);
        ASSERT(result.has_value(), "There should be an even number");
        ASSERT(result.value() == 8, "The even number should be 8");

        // value_or
        std::vector<int> odd_nums{1, 3, 5, 7};
        auto no_even = find_even(odd_nums);
        int default_value = no_even.value_or(-1);
        ASSERT(default_value == -1, "Default value should be -1 when no even number is found");
    }
    {
        // emplace
        std::optional<int> opt_value;
        ASSERT(!opt_value.has_value(), "Optional should initially have no value");
        opt_value.emplace(42);
        ASSERT(opt_value.has_value(), "Optional should now have a value");
        ASSERT(opt_value.value() == 42, "The value should be 42");

        // std::nullopt
        std::optional<int> empty_opt;
        ASSERT(empty_opt == std::nullopt, "Optional should be equal to std::nullopt when empty");
        ASSERT(opt_value != std::nullopt, "Optional with a value should not be equal to std::nullopt");

        // reset
        opt_value.reset();// 清除值
        ASSERT(!opt_value.has_value(), "Optional should have no value after reset");
        ASSERT(opt_value == std::nullopt, "Optional should be equal to std::nullopt when empty");
    }
    return 0;
}