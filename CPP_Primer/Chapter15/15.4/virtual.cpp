//
// Created by bowen on 2020/8/22.
//

#include <iostream>
class A{
public:
//    virtual void f(int) = 0; // pass, pure virtual
//    virtual void f(int) ; // fail, no def
    virtual void f(int){}; // pass, empty def


};

class B: public A {
public:
    void f(int) override {
        std::cout << "I' m B\n";
    }
};

class C: public B {
public:
    void  f(int) override {
        std::cout << "I' m C\n";
    }
};

int main() {
    B b;
    b.f(1);

    C c;
    c.f(1);
}
