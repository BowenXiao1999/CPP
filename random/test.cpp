#include <iostream>
class B {
    public:
    B(size_t & a): a_(a) {
    }

    void show() {
        std::cout << a_ << std::endl;
    }
private:
    const size_t & a_;
};
class A {
    public:
    A(size_t a) : b(a), b_{b}{
        b = a;
    }

    size_t b;
    B b_;
};


int main() {
    // Test 1.
    size_t a = 5;
    const size_t & b = a;
    std::cout << b << std::endl;
    a = 3;
    std::cout << b << std::endl;

    // Test 2.
    A i(5);
    i.b_.show();
    i.b++;
    i.b_.show();

}

