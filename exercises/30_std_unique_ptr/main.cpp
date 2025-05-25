#include "../exercise.h"
#include <memory>
#include <string>
#include <vector>
#include <cstring>

// READ: `std::unique_ptr` <https://zh.cppreference.com/w/cpp/memory/unique_ptr>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        _records.push_back(record);
    }

    void print() const {
        std::cout << _records << std::endl;
    }

    ~Resource() {
        std::cout << "Resource destructor called" << std::endl;
        print();
        RECORDS.push_back(_records);
    }
};

using Unique = std::unique_ptr<Resource>;
Unique reset(Unique ptr) {
    std::cout << "reset" << std::endl;
    if (ptr) {
        ptr->record('r');
        std::cout << "after reset, _records: ";
        ptr->print();
        //*
        ptr.reset();
    }
    return std::make_unique<Resource>();
}
Unique drop(Unique ptr) {
    std::cout << "drop" << std::endl;
    if (ptr) {
        ptr->record('d');
        std::cout << "after drop, _records: ";
        ptr->print();
    }
    return nullptr;
}
Unique forward(Unique ptr) {
    std::cout << "forward" << std::endl;
    if (ptr) {
        ptr->record('f');
        std::cout << "after forward, _records: ";
        ptr->print();
    }
    return ptr;
}

int main(int argc, char **argv) {
    std::vector<std::string> problems[3];

    drop(forward(reset(nullptr)));
    problems[0] = std::move(RECORDS);

    std::cout << "------------------------" << std::endl;

    forward(drop(reset(forward(forward(reset(nullptr))))));
    problems[1] = std::move(RECORDS);

    std::cout << "------------------------" << std::endl;

    drop(drop(reset(drop(reset(reset(nullptr))))));
    problems[2] = std::move(RECORDS);

    // ---- 不要修改以上代码 ----

    std::vector<const char *> answers[]{
        {"fd"},
        // TODO: 分析 problems[1] 中资源的生命周期，将记录填入 `std::vector`
        // {"d", "ffr"},
        // {"d", "d", "r"},
        {"ffr", "d"},
        {"r", "d", "d"},
    };

    // ---- 不要修改以下代码 ----

    for (auto i = 0; i < 3; ++i) {
        ASSERT(problems[i].size() == answers[i].size(), "wrong size");
        for (auto j = 0; j < problems[i].size(); ++j) {
            ASSERT(std::strcmp(problems[i][j].c_str(), answers[i][j]) == 0, "wrong location");
        }
    }

    return 0;
}
