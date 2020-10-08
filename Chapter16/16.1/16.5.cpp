//
// Created by bowen on 2020/8/16.
//

#include <iostream>
#include <vector>
using namespace std;

// Can receive any array with any length and print it out
template<typename T, size_t N> void print(const T (&a)[N]) {
    for (auto iter = begin(a); iter != end(a) ;iter++) {
        std::cout << *iter << std::endl;
    }
}

int main(){
    int v1[6] = {1, 2, 3, 4, 5, 6};
    print(v1);

    std::string v2[3] = {"wo", "shi", "ni"};
    print(v2);
}
