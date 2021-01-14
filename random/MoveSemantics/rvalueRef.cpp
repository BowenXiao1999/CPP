#include <iostream>
#include <utility>
#include <assert.h>
using  std::move;

class A {
public:
    int* n;
    A(): n(new int[5]) {};

    A(int n) : n(new int[5]) {};

    A(A && a) {
        n = a.n;
        a.n = nullptr;
        std::cout << "Move constructor!" << std::endl;
    }

    A& operator=(A && a) {
        this->n = a.n;
        a.n = nullptr;
        std::cout << "Move assignment!" << std::endl;
        return *this;
    }
};

int main() {
    A a(5);

    A b = std::move(a); // ok
//    A & d = std::move(b); // fail
    const A &c = std::move(b); // ok, but not use move constructor/assignment. Why?
    assert(b.n != nullptr);
}
