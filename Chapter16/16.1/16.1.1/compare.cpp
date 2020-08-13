#include <iostream>

// template function
template <typename T> 
int compare(const T& a, const T& b) {
    if (a > b) {
        return 1;
    }else{
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << compare(2, 1) << std::endl;
    std::cout << compare("aa", "ab") << std::endl;
    return 0;
}
