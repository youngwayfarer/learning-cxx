add_rules("mode.debug", "mode.release")
set_encodings("utf-8")
set_warnings("all")
set_kind("binary")
set_languages("cxx17")

-- 格式化输出
target("exercise00")
    add_files("00_hello_world/main.cpp")

-- 变量与运算符
target("exercise01")
    add_files("01_variable&add/main.cpp")

-- 函数、声明和定义
target("exercise02")
    add_files("02_function/main.cpp")

-- 形参实参
target("exercise03")
    add_files("03_argument&parameter/main.cpp")

-- static 关键字
target("exercise04")
    add_files("04_static/main.cpp")

-- constexpr 编译时常量和运算
target("exercise05")
    add_files("05_constexpr/main.cpp")

-- 数组
target("exercise06")
    add_files("06_array/main.cpp")

-- 循环
target("exercise07")
    add_files("07_loop/main.cpp")

-- 指针
target("exercise08")
    add_files("08_pointer/main.cpp")

-- 枚举/联合体
target("exercise09")
    add_files("09_enum&union/main.cpp")

-- “普通”类型
target("exercise10")
    add_files("10_trivial/main.cpp")

-- 方法
target("exercise11")
    add_files("11_method/main.cpp")

-- const 修饰方法
target("exercise12")
    add_files("12_method_const/main.cpp")

-- 类
target("exercise13")
    add_files("13_class/main.cpp")

-- 析构器
target("exercise14")
    add_files("14_class_destruct/main.cpp")

-- 复制构造函数
target("exercise15")
    add_files("15_class_clone/main.cpp")

-- 移动语义
target("exercise16")
    add_files("16_class_move/main.cpp")

-- 派生
target("exercise17")
    add_files("17_class_derive/main.cpp")

-- 虚函数
target("exercise18")
    add_files("18_class_virtual/main.cpp")

-- 虚析构函数
target("exercise19")
    add_files("19_class_virtual_destruct/main.cpp")

-- 函数模板
target("exercise20")
    add_files("20_function_template/main.cpp")

-- 习题：用于编译器的运行时类型
target("exercise21")
    add_files("21_runtime_datatype/main.cpp")

-- 类模板
target("exercise22")
    add_files("22_class_template/main.cpp")

-- 模板非类型实参
target("exercise23")
    add_files("23_template_const/main.cpp")

-- std::array
target("exercise24")
    add_files("24_std_array/main.cpp")

-- std::vector
target("exercise25")
    add_files("25_std_vector/main.cpp")

-- std::vector<bool>
target("exercise26")
    add_files("26_std_vector_bool/main.cpp")

-- 习题：步长计算
target("exercise27")
    add_files("27_strides/main.cpp")

-- std::string
target("exercise28")
    add_files("28_std_string/main.cpp")

-- std::map
target("exercise29")
    add_files("29_std_map/main.cpp")

-- std::transform
target("exercise30")
    add_files("30_std_unique_ptr/main.cpp")

-- std::accumulate
target("exercise31")
    add_files("31_std_shared_ptr/main.cpp")

-- std::transform
target("exercise32")
    add_files("32_std_transform/main.cpp")

-- std::accumulate
target("exercise33")
    add_files("33_std_accumulate/main.cpp")

-- TODO: lambda; deque; forward_list; fs; thread; mutex;

-- lambda
target("exercise34")
    add_files("34_lambda/main.cpp")

-- optional
target("exercise35")
    add_files("35_optional/main.cpp")

-- variant
target("exercise36")
    add_files("36_variant/main.cpp")

-- std::deque
target("exercise37")
    add_files("37_std_deque/main.cpp")

-- std::forward_list
target("exercise38")
    add_files("38_std_forward_list/main.cpp")

-- std::filesystem
target("exercise39")
    add_files("39_std_fs/main.cpp")

-- std::thread
target("exercise40")
    add_files("40_std_thread/main.cpp")

-- std::mutex
target("exercise41")
    add_files("41_std_mutex/main.cpp")
