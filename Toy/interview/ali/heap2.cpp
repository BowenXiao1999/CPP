//
// Created by bowen on 2020/10/11.
//
using namespace std;
#include <vector>
class Heap {

public:
    vector<int> k;
    Heap(vector<int>& a) : k(a) {}
    void Heapify();
    void swap(int *, int*);
    int DeleteMin();
    void pushDown(int);
};

void Heap::Heapify() {
    int n = k.size();
    int beginIndex = n/2 - 1;
    for (int i = beginIndex; i >= 0; i--) {
        int swapIndex = -1;
        int leftChild = i*2+1 < n? i*2+1: -1;
        int rightChild = i*2 + 2 < n? i*2+2: -1;
        if (leftChild != -1 && rightChild != -1) swapIndex = k[leftChild] > k[rightChild] ? rightChild: leftChild;
        else if (leftChild != -1 && rightChild == -1) swapIndex = leftChild;
        else swapIndex = -1;

        if (swapIndex != -1 && k[swapIndex] < k[i]) {
            swap(&k[swapIndex], &k[i]);
            pushDown(swapIndex);
        }
    }
}

void Heap::swap(int * a, int * b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int Heap::DeleteMin() {

    int ret = k[0];
    int replaceIndex = k.size() - 1;
    swap(&k[replaceIndex], &k[0]);
    k.pop_back();

    // push down from top
    pushDown(0);


    return ret;
}

void Heap::pushDown(int i) {

    while (i*2 + 1 < k.size()){
        int swapIndex = -1;
        int leftChild = i * 2 + 1 < k.size()? i * 2  + 1: -1;
        int rightChild = i * 2 + 2 < k.size()? i * 2  + 2: -1;
        if (leftChild != -1 && rightChild != -1) swapIndex = k[leftChild] > k[rightChild] ? rightChild: leftChild;
        else if (leftChild != -1 && rightChild == -1) swapIndex = leftChild;
        else swapIndex = -1;

        if (swapIndex != -1 && k[swapIndex] < k[i]) {
            swap(&k[swapIndex], &k[i]);
            i = swapIndex;
        }
        else break;
    }
}
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ret;
        Heap h(arr);
        h.Heapify();
        if (arr.size() >= k) {
            for (int i = 0; i < k; i++) {
                ret.push_back(h.DeleteMin());
            }
        }else{
            return arr;
        }
        return ret;
    }
};