//
// Created by bowen on 2020/8/26.
//

#include <iostream>

struct B {
    int idd;
};

// use typedef to define
typedef B C[5];

// use using to define
int main() {
    const int N = 5;
    using A = B[N];

}
