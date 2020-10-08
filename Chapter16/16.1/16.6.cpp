//
// Created by bowen on 2020/10/7.
//
#include <iostream>
using namespace std;
template<typename T, size_t N>
 T* my_begin(const T (&a)[N]) {
     return &(a[0]);
 }

template<typename T, size_t N> T* my_end(const T (&a)[N]) {
    return &(a[0]) + N;
}