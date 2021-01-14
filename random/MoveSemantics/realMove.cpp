#include <iostream>
#include <utility>
#include <memory>
using std::move;
void test (std::unique_ptr<int*> && a) {
    // do nothing
}
void test2 (const std::unique_ptr<int*> & a) {
    // do nothing
}
void test3 (std::unique_ptr<int*>  a) {
    // do nothing
}
void test4 (const std::unique_ptr<int*> & a) {
    // do nothing
}
int main() {
    auto a = std::make_unique<int*>(new int(10));

    test(std::move(a));
    // 1. why it do not crash
    std::cout << *a << std::endl;

    test2(std::move(a));
    std::cout << *a << std::endl;

//    test4(std::move(a));  // why it crash here but test2 ok
//    std::cout << *a << std::endl;

    test2(std::move(a));
//    std::cout << *a << std::endl; // 3. why it crash here

    return 0;
}
