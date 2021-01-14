//
// Created by bowen on 2020/10/3.
//
#include <iostream>
#include <string>
using std::string;
class StrVec {
public:
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &); // copy construct
    StrVec & operator=(const StrVec&);
    ~StrVec();
    void push_back(const string &);
    size_t size() const {first_free - elements};
    size_t capacity() const {cap - elements};
    string * begin() const {return elements};
    string * end() const {return first_free};

private:
    string * elements;
    string * first_free;
    string * cap;

};