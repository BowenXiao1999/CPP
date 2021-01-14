//
// Created by bowen on 2020/9/11.
//
#include <map>
#include <iostream>
using namespace std;

struct Element {
    int key;
    int val;
};


struct LRUCache {
    int cap;
    linkedList<Element*> ll;
    unordered_map<int, Element*> m;
    LRUCache(int cap){
        this->cap = cap;
    }
    int get(int key);
    void put(int key, int value);
};

int LRU::get(int key) {
    // if find in map
    if (this->m.find(key) != m.end()) {
        auto ret = *(m.find(key));

        // move front
        this->ll.moveToFront(ret);
        return ret->val;
    }
    return -1;
}

void LRU::put(int key, int value) {
    if (this->m.find(key) != m.end()) {
        auto ret = *(m.find(key));
        ret->value = value;
        this->ll.moveToFront(ret);
    }else{
        if (this->ll.size() == this->cap) {
            auto r = this->ll.back();
            m.erase(r->key);
            this->ll.popBack();
            free(r);
        }
        Element* a = new Element{key, val};
        this->m.insert(key, a);
        this->ll.insertFront(a);
    }
}




