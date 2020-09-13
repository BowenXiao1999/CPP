//
// Created by bowen on 2020/9/14.
//



struct Node {
    int value;
    Node *next;
}


// sortArray: k个n
// O((logk)kn)) A, B(j)
// (kn)*log(kn)
Node
*
merge(vector<Node *>
sortArrays) {

// init
int k = sortArrays.size()
Heap<Node *> h(k);
Node *dummy;
Node *ptr;
// Node* dummy = new Node();
// dummy.next = nullptr;
// Node* ptr = dummy;

// extreme case
// if (k == 0) {
//  return dummy
// }

// first append all root Node into heap
for (
auto i
: sortArrays) {
if (i) h.
push(i);
}
bool first = true;

// keep tracing each list until heap is empty
while (h.

size()

!= 0) {
auto evict = h.min();
h.

deleteMin();
// ptr.next = evict;
if (dummy == null) {
dummy = evict;
ptr = dummy;
first = false;
}
else {
ptr.
next = evict;
ptr = ptr.next;
}
// ptr = ptr.next;

auto next = evict.next;
if (next) h.
push(next);
}

return
dummy;
}

class Heap {
    vector<Node *> stk;

    void push(Node *n) {
        stk.push(n);
        int idx = stk.size() - 1;
        Node * replace = n;
        while (idx > 0) {
            int parent = (idx - 1) / 2;

            if (stk[parent].val > stk[idx].val) {
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

    Node* delete(
    int index
    ){

    }


}