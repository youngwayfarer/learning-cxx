#include "../exercise.h"
#include <algorithm>
#include <vector>

// READ: `lambda` <https://zh.cppreference.com/w/cpp/language/lambda>

int main(int argc, char **argv) {
    {
        std::vector<int> numbers{1, 2, 3, 4, 5};
        int sum = 0;

        std::for_each(numbers.begin(), numbers.end(), [&sum](int n) {
            sum += n;
        });

        // TODO: 为下列 ASSERT 填写正确的值
        ASSERT(sum == ?, "Sum of numbers should be ?");

        auto is_even = [](int n) { return n % 2 == 0; };
        std::vector<int> evens;
        std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens), is_even);

        ASSERT(evens.size() == ?, "There should be ? even numbers");
        ASSERT(evens[0] == ? && evens[1] == ?, "Even numbers should be ?");

        // TODO: 使用 Lambda 表达式计算奇数的平方和
        int odd_square_sum = 0;
        std::for_each(numbers.begin(), numbers.end(), ?);
        ASSERT(odd_square_sum == 35, "Sum of squares of odd numbers should be 35");
    }
    {
        // TODO: 为下面的 ? 填写正确的值
        auto create_adder = [](int x) {
            return [x](int y) { return x + y; };
        };
        auto add_five = create_adder(?);
        ASSERT(add_five(?) == 8, "5 + 3 should be 8");

        // 创建一个乘法器的 Lambda 表达式
        // TODO: 返回一个 Lambda 表达式
        auto create_multiplier = ?;
        auto multiply_by_three = create_multiplier(3);
        ASSERT(multiply_by_three(4) == 12, "3 * 4 should be 12");
    }
    {
        // 使用 Lambda 表达式捕获外部变量
        // TODO: 为下面的 ? 填写正确的表达式
        int factor = 10;
        auto multiply_by_factor = [?](int x) {
            return x * factor;
        };
        ASSERT(multiply_by_factor(2) == 20, "2 * 10 should be 20");
    }
    {
        // 递归 Lambda 表达式（计算阶乘）
        std::function<int(int)> factorial;
        // TODO: 替换下面的 ?，实现正确的 Lambda 表达式，计算阶乘
        factorial = [?](int n) {
            ?
        };

        ASSERT(factorial(0) == 1, "Factorial of 0 should be 1");
        ASSERT(factorial(5) == 120, "5! should be 120");
        ASSERT(factorial(7) == 5040, "7! should be 5040");

        // 递归 Lambda 表达式（fibonacci 数列）
        // TODO: 替换下面的 ?，实现正确的 Lambda 表达式，计算 fibonacci 数列
        std::function<int(int)> fib;
        fib = [?](int n) {
            ?
        };
        ASSERT(fib(7) == 13, "7th Fibonacci number should be 13");
    }
    return 0;
}
