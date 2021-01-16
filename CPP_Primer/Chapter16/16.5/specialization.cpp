//
// Created by BowenXiao on 2021/1/17.
//

#include <iostream>
using namespace std;


template <typename T>
class Add {
public:
    const T & add(const T& t1, const T& t2) {
        cout << "General\n";
        return t1 + t2;
    }
};

template <>
class Add<int> {
public:
    const int & add (const int & t1, const int & t2) {
        cout << "Special\n";
        return t1 + t2;
    }
};

int main() {

    Add<float> fl;
    fl.add(1.0, 2.0);

    Add<int> i;
    i.add(1, 3);
    return 0;
}
