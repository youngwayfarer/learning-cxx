#include "../exercise.h"
#include <iostream>
#include <variant>

// READ: `variant` <https://zh.cppreference.com/w/cpp/utility/variant>

int main(int argc, char **argv) {
    {
        // 基本使用
        std::variant<int, std::string> var;

        var = 42;
        ASSERT(std::get<int>(var) == 42, "Variant should hold an int");

        var = "Hello, variant!";
        ASSERT(std::get<std::string>(var) == "Hello, variant!", "Variant should hold a string");
    }
    {
        // visit
        std::variant<int, std::string> var2 = 100;
        std::visit([](auto &&value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, int>) {
                ASSERT(value == 100, "Value should be 100");
            } else if constexpr (std::is_same_v<T, std::string>) {
                ASSERT(false, "Unexpected type");
            }
        },
                   var2);

        // holds_alternative
        ASSERT(std::holds_alternative<int>(var2), "Variant should hold an int");
        ASSERT(!std::holds_alternative<std::string>(var2), "Variant should not hold a string");

        // 异常处理
        try {
            std::get<std::string>(var2);
        } catch (const std::bad_variant_access &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    {
        std::variant<int, double, std::string> var3 = 3.14;
        ASSERT(std::holds_alternative<double>(var3), "Variant should hold a double");
        ASSERT(std::get<double>(var3) == 3.14, "Value should be 3.14");

        var3 = "Variant supports multiple types!";
        ASSERT(std::holds_alternative<std::string>(var3), "Variant should hold a string");
        ASSERT(std::get<std::string>(var3) == "Variant supports multiple types!", "String value mismatch");
    }
    return 0;
}