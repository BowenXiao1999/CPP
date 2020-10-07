//
// Created by bowen on 2020/9/21.
//
#include <vector>
using namespace std;
struct Node {
    Node* next;
    int val;
};
class Heap {
    vector<Node *> stk;

    void push(Node *n) {
        stk.push_back(n);
        int idx = stk.size() - 1;
        Node * replace = n;
        while (idx > 0) {
            int parent = (idx - 1) / 2;

            if (stk[parent]->val > stk[idx]->val) {
                stk[idx] = stk[parent];
                idx = parent;
            } else {
                break;
            }
        }

        stk[idx] = replace;


    }

    Node *min() {
        return stk[0];
    }

    Node* Delete( int index );
    Node* deleteMin();


};

Node* Heap::deleteMin() {
    // swap the last one with these
    auto last = stk.back();
    auto tmp = stk[0];
    stk[0] = last;
    stk[stk.size()-1] = tmp;
    stk.pop_back();

    // push from top down
    int parent_left = 1;
    int parent_right = 2;
    int now = 0;
    while (parent_left < stk.size() || parent_right < stk.size()) {
        int smaller = -1;
        int left = parent_left < stk.size() ? parent_left: -1;
        int right = parent_right < stk.size() ? parent_right: -1;
        if (left != -1 && right == -1) {
            smaller = left;
        } else{
            if (stk[left]->val > stk[right]->val) smaller = right;
            else smaller = left;
        }

        if (stk[smaller]->val < stk[now]->val) {
            //swap it
            auto tmp = stk[smaller];
            stk[smaller] = stk[now];
            stk[now] = tmp;
            now = smaller;
            parent_left = now * 2 + 1;
            parent_right = now * 2 + 2;
        } else break;
    }
}