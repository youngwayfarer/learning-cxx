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
    {
        // 测试递归Lambda表达式（计算阶乘）
        std::function<int(int)> factorial;
        factorial = [&factorial](int n) {
            return n <= 1 ? 1 : n * factorial(n - 1);
        };

        ASSERT(factorial(0) == 1, "Factorial of 0 should be 1");
        ASSERT(factorial(5) == 120, "5! should be 120");
        ASSERT(factorial(7) == 5040, "7! should be 5040");

        // 测试递归Lambda的闭包特性
        std::function<int(int)> fib;
        fib = [&fib](int n) {
            return n <= 2 ? 1 : fib(n - 1) + fib(n - 2);
        };
        ASSERT(fib(7) == 13, "7th Fibonacci number should be 13");
    }
    return 0;
}
