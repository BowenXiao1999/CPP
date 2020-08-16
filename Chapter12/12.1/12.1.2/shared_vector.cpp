//
// Created by bowen on 2020/8/16.
//

#include <memory>
#include <iostream>
#include <vector>

std::shared_ptr<std::vector<int>> newVector() {
    return std::make_shared<std::vector<int>>();
}

void readInts(std::shared_ptr<std::vector<int>> a) {
    int v1;
    std::cin >> v1;
    a->push_back(v1);
}

int main() {

    auto i = newVector();
    readInts(i);

    // do not care about memory leakage


    // compare cases
    int *p1 = new int(42), *p2 = new int(100);
    p1 = p2; // memory leakage + null ptr problems

    auto i = std::make_shared<int>(42), j = std::make_shared<int>(100);
    i = j; // perfect

}


