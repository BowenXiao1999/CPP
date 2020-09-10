//
// Created by bowen on 2020/9/9.
//
#include <utility>
#include <iostream>
#include <string.h>
#include <algorithm>
//#include <string_view>
using namespace std;
class MyString {
private:
    char *data_;
public:
    MyString(): data_(new char[1]){*data_ = '\0';}
    MyString(const char *ori): data_(new char[strlen(ori)+1]) {strcpy(data_, ori);}
    MyString(MyString &ori): data_(new char[ori.size()+1]) {strcpy(data_, ori.data_);}
    MyString(MyString &&ori): data_(ori.data_) {ori.data_ = nullptr;}
    ~MyString(){delete [] data_;}
    void swap(MyString& ms) {std::swap(data_, ms.data_);}
    // assign
    MyString& operator=(MyString rhs) {swap(rhs); return *this;}
    MyString& operator=(MyString &&rhs) {swap(rhs); return *this;}
    size_t size() {return strlen(data_);}
};


// expected string
int main() {
    MyString a1;
    MyString a2("Good");
    MyString a3(a1);
    MyString a4 = a1;
    a3 = a2;
}
