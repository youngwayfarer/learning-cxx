#include "../exercise.h"
#include <filesystem>
#include <fstream>

// READ: `std::filesystem` <https://zh.cppreference.com/w/cpp/filesystem>

int main(int argc, char **argv) {
    namespace fs = std::filesystem;

    {
        // 获取当前路径
        fs::path current_path = fs::current_path();
        ASSERT(!current_path.empty(), "Current path should not be empty");
    }
    {
        // 创建和删除目录
        fs::path test_dir = "test_directory";
        fs::create_directory(test_dir);
        ASSERT(fs::exists(test_dir), "Directory should exist after creation");

        fs::remove(test_dir);
        ASSERT(!fs::exists(test_dir), "Directory should not exist after removal");
    }
    {
        // 文件操作
        fs::path test_file = "test_file.txt";
        std::ofstream ofs(test_file);
        ofs << "Hello, filesystem!";
        ofs.close();

        ASSERT(fs::exists(test_file), "File should exist after creation");

        // 从文件中读取内容并比较
        std::ifstream ifs(test_file);
        std::string content;
        std::getline(ifs, content);
        ASSERT(content == "Hello, filesystem!", "File content should match the written content");
        ifs.close();

        auto file_size = fs::file_size(test_file);
        ASSERT(file_size == 18, "File size should be 18");

        fs::remove(test_file);
        ASSERT(!fs::exists(test_file), "File should not exist after removal");
    }
    return 0;
}
