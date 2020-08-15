//
// Created by bowen on 2020/8/15.
//
#include <iostream>
#include <vector>
#include <string>
#include <list>

template<typename I, typename V> I find(I start, I end, const V& v) {
    while (start != end && *start != v) {
        start++;
    }
    return start;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto r1 = find(v.begin(), v.end(), 6);
    if (r1 != v.end())
        std::cout << "find it " << *r1 << std::endl;
    else
        std::cout << "Not find it"  << std::endl;

    std::list<std::string> v2 = {"Bad", "Bitches"};
    auto r2 = find(v2.begin(), v2.end(), "Beaches");
    if (r2 != v2.end())
        std::cout << "find it " << *r2 << std::endl;
    else
        std::cout << "Not find it" << std::endl;

    return 0;
}

