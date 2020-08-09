#include <vector>
#include <iostream>
#include <string>
void showVectorInt(std::vector<int> a) {
    std::cout << "The size is " << a.size() << std::endl;
    for (auto i = a.begin(); i != a.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void showVectorString(std::vector<std::string> a) {
    std::cout << "The size is " << std::endl;
    for (auto i = a.begin(); i != a.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);

    // Compiler not support
    // std::vector<int> v4{10};
    // std::vector<int> v5{10, 42};
    // std::vector<std::string> v6{10};
    // std::vector<std::string> v7{10, "hi"};

    showVectorInt(v1);
    showVectorInt(v2);
    showVectorInt(v3);
    // showVectorInt(v4);
    // showVectorInt(v5);
    // showVectorString(v6);
    // showVectorString(v7);

    return 0;
}
