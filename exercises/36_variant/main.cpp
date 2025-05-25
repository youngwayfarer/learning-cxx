#include "../exercise.h"
#include <iostream>
#include <variant>

// READ: `variant` <https://zh.cppreference.com/w/cpp/utility/variant>

int main(int argc, char **argv) {
    // TODO: 为下列 ASSERT 填写正确的值
    {
        std::variant<int, std::string> var;

        var = 42;
        ASSERT(std::get<int>(var) == ?, "Variant should hold an int");

        var = "Hello, variant!";
        ASSERT(std::get<std::string>(var) == ?, "Variant should hold a string");
    }
    {
        std::variant<int, std::string> var2 = 100;
        std::visit([](auto &&value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, int>) {
                ASSERT(value == ?, "Value should be ?");
            } else if constexpr (std::is_same_v<T, std::string>) {
                ASSERT(?, "填入 true 或 false");
            }
        },
                   var2);

        ASSERT(std::holds_alternative<?>(var2), "填入正确的数据类型");
        ASSERT(!std::holds_alternative<?>(var2), "填入正确的数据类型");

        try {
            std::get<std::string>(var2);
        } catch (const std::bad_variant_access &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    {
        std::variant<int, double, std::string> var3 = 3.14;
        ASSERT(std::holds_alternative<?>(var3), "填入正确的数据类型");
        ASSERT(std::get<double>(var3) == ?, "Value should be ?");

        var3 = "Variant supports multiple types!";
        ASSERT(std::holds_alternative<?>(var3), "填入正确的数据类型g");
        ASSERT(std::get<std::string>(var3) == ?, "String value mismatch");
    }
    return 0;
}