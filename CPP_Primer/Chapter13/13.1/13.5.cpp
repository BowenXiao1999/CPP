//
// Created by bowen on 2020/8/28.
//

#include <string>
#include <iostream>

using namespace std;
class HasPtr {
public:
    string* ps;
    int i;
    HasPtr(const string& s = string()):
    ps(new string(s)), i(0) {}

    HasPtr(const HasPtr& orig);
    HasPtr& operator=(const HasPtr&);
};


// copy construct
HasPtr::HasPtr(const HasPtr &orig) {
    cout << "copy construct\n";
    ps = new string (*orig.ps); // 拷贝对象，而不是拷贝指针本身
    i = orig.i;

}

// copy assignment
HasPtr& HasPtr::operator=(const HasPtr& orig) {
    delete ps;
    cout << "This is in copy assignment\n";
    auto newps = new string(*orig.ps);
    ps = newps;
    i = orig.i;
}

HasPtr Global;
HasPtr Test(HasPtr a) {
    HasPtr local = a;
    HasPtr* heap = new HasPtr(Global);
//    *heap = Global; // this line should call copy assignment instead of copy construct
    HasPtr arr[4] = {local, *heap};
    return *heap;
}
int main() {
    Test(Global);
}
