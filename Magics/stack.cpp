//
// Created by bowen on 2020/8/27.
//
#include <iostream>
template <typename T> class STK {
public:
    T* p;
    int pushIndex;
    int popIndex;
    int count;
    int cap;
    STK(int n) {
      p = new T[n];
      cap = n;
      pushIndex = 0;
      popIndex = 0;
      count = 0;
      for (int i = 0; i < n; i++){
          p[i] = 0;
      }
    }

    void push(T a) {
        if (count < cap) {
            p[pushIndex] = a;
            pushIndex = (pushIndex + 1) % cap;
            count++;
        }else{
            pop();
            push(a);
            std::cout << "Full\n";
        }
    }

    void pop() {
        if (count > 0) {
            p[popIndex] = NULL;
            popIndex = (popIndex + 1) % cap;
            count--;
        }else{
            std::cout << "Empty\n";
        }
    }
};

int main() {
    // fail the last push one
    STK<int> a(2);
    a.push(1);
    a.push(2);
    a.push(3); // Full and fail 1

    for (int i = 0; i < 2; i++) {
        std::cout << a.p[i] << " "; // 3, 2
    }
    std::cout << std::endl;

    //
    STK<int> b(5);
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6); // Full and fail 1
    b.push(7); // Full and fail 1
    b.pop();
    for (int i = 0; i < 5; i++) {
        std::cout << b.p[i] << " "; // 3, 2
    }
    std::cout << std::endl;

    b.push(99);
    for (int i = 0; i < 5; i++) {
        std::cout << b.p[i] << " "; // 3, 2
    }
    std::cout << std::endl;
}

