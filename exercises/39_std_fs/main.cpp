#include "../exercise.h"
#include <filesystem>
#include <fstream>

// READ: `std::filesystem` <https://zh.cppreference.com/w/cpp/filesystem>

int main(int argc, char **argv) {
    namespace fs = std::filesystem;

    // TODO: 为下列 ASSERT 填写正确的值
    {
        // 获取当前路径
        fs::path current_path = fs::current_path();
        ASSERT(?, "填入 current_path.empty() 或者 !current_path.empty()");
    }
    {
        fs::path test_dir = "test_directory";
        fs::create_directory(test_dir);
        ASSERT(?, "填入 fs::exists(test_dir) 或者 !fs::exists(test_dir)");

        fs::remove(test_dir);
        ASSERT(?, "填入 fs::exists(test_dir) 或者 !fs::exists(test_dir)");
    }
    {
        fs::path test_file = "test_file.txt";
        std::ofstream ofs(test_file);
        ofs << "Hello, filesystem!";
        ofs.close();

        ASSERT(?, "填入 fs::exists(test_file) 或者 !fs::exists(test_file)");

        std::ifstream ifs(test_file);
        std::string content;
        std::getline(ifs, content);
        ASSERT(content == ?, "File content should match the written content");
        ifs.close();

        auto file_size = fs::file_size(test_file);
        ASSERT(file_size == ?, "File size should be ?");

        fs::remove(test_file);
        ASSERT(!fs::exists(test_file), "File should not exist after removal");
    }
    return 0;
}
