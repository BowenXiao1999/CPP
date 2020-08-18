//
// Created by bowen on 2020/8/18.
//

#include <cstring>
#include <string>
#include <iostream>

int main() {
    // concat two string in C++ style
    std::string a = "hello";
    std::string b = "world";
    std::string c = a + " " + b;
    std::cout << c << std::endl;


    // concat two string in C style
    const char ac[] = "hello"; // paddded a empty bit
    const char bc[] = "world";
    char cc[10];
    strcpy(cc, ac);
    strcat(cc, " ");
    strcat(cc, bc);
    std::cout << cc << std::endl;




}