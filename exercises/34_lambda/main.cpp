#include "../exercise.h"
#include <algorithm>
#include <functional>
#include <vector>

// READ: `lambda` <https://zh.cppreference.com/w/cpp/language/lambda>

int main(int argc, char **argv) {
    {
        std::vector<int> numbers{1, 2, 3, 4, 5};
        int sum = 0;

        // 使用 Lambda 表达式计算总和
        std::for_each(numbers.begin(), numbers.end(), [&sum](int n) {
            sum += n;
        });

        ASSERT(sum == 15, "Sum of numbers should be 15");

        // 使用 Lambda 表达式过滤数据
        auto is_even = [](int n) { return n % 2 == 0; };
        std::vector<int> evens;
        std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens), is_even);

        ASSERT(evens.size() == 2, "There should be 2 even numbers");
        ASSERT(evens[0] == 2 && evens[1] == 4, "Even numbers should be 2 and 4");

        // 使用 Lambda 表达式计算奇数的平方和
        int odd_square_sum = 0;
        // 填空：使用 std::for_each 和 Lambda 表达式
        std::for_each(numbers.begin(), numbers.end(), [&odd_square_sum](int n) {
            if (n % 2 != 0) {
                odd_square_sum += n * n;
            }
        });
        ASSERT(odd_square_sum == 35, "Sum of squares of odd numbers should be 35");
    }
    {
        // 使用 Lambda 表达式作为返回值
        auto create_adder = [](int x) {
            return [x](int y) { return x + y; };
        };
        auto add_five = create_adder(5);
        ASSERT(add_five(3) == 8, "5 + 3 should be 8");

        // 创建一个乘法器的 Lambda 表达式
        auto create_multiplier = [](int x) {
            // 填空：返回一个 Lambda 表达式
            return [x](int y) { return x * y; };
        };
        auto multiply_by_three = create_multiplier(3);
        ASSERT(multiply_by_three(4) == 12, "3 * 4 should be 12");
    }
    {
        // 使用 Lambda 表达式捕获外部变量
        int factor = 10;
        auto multiply_by_factor = [factor](int x) {
            return x * factor;
        };
        ASSERT(multiply_by_factor(2) == 20, "2 * 10 should be 20");

        // 修改捕获的变量
        factor = 5;
        ASSERT(multiply_by_factor(2) == 20, "Captured factor should not change");
    }
    return 0;
}
