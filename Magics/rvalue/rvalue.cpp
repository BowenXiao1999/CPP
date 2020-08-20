//
// Created by bowen on 2020/8/19.
//

#include <iostream>
int a(const int &b){
    std::cout << "Good";
}

//int a(int &b){ // fail because of int & is a lvalue, but int is a rvalue
//    std::cout << "Good";
//}

int main() {
    a(5);
}
