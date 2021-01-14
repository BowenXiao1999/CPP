//
// Created by bowen on 2020/8/19.
//

#include <cassert>
#define NDEBUG // why I can not use NDEBUG
#include <iostream>
int main(){
    std::cout << __func__ << std::endl;
    std::cout << __FILE__ << std::endl;
    std::cout << __LINE__ << std::endl;
    std::cout << __TIME__ << std::endl;
    std::cout << __DATE__ << std::endl;
#ifndef NDEBUG
    assert(1+1 < 0);
#endif
}
