#include <iostream>
#include <string>

class Person {
    public:
    std::string name;
    std::string address;    
    Person(std::string n, std::string a) {
        this->name = n;
        this->address = a;
    }

    std::string GetAddress() {
        return address;
    }

    std::string GetName() {
        return name;
    }
};