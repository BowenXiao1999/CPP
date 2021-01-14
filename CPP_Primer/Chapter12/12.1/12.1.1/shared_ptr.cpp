//
// Created by bowen on 2020/8/16.
//

#include <memory>
#include <vector>
#include <iostream>

int main() {

    // shared ptr share one object
    std::shared_ptr<std::vector<std::string>> p1;
    {
        std::shared_ptr<std::vector<std::string>> p2 = std::make_shared<std::vector<std::string>>(std::vector<std::string>{"wo", "ai", "ni"});
        p1 = p2;
        p1->push_back("ma");
    }
    std::cout << p1->size() << /*p2->size() <<*/ std::endl;
}

