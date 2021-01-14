//
// Created by BowenXiao on 2021/1/14.
//

#include <memory>
#include <utility>
#include <iostream>
class A {
public:
    std::unique_ptr<int*> buffer;
    A(std::unique_ptr<int*> ptr) {
        buffer = std::move(ptr);
        std::cout << "A\n";
    }
};
class B {
public:
    std::unique_ptr<int*> buffer;
    B(std::unique_ptr<int*> && ptr) {
        buffer = std::move(ptr);
        std::cout << "B\n";
    }
};
int main() {
    auto a = std::make_unique<int*>(new int[5]);
    auto b = std::make_unique<int*>(new int[5]);
    // 1.
    A(std::move(a));
    // 2.
    B(std::move(b));
    return 0;
}

