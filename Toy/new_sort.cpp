//
// Created by bowen on 2020/9/8.
//
#include <vector>
#include <iostream>
using namespace std;

// return value is a pair, represent the truncated slice index in a and b
pair<int, int> divide(vector<int> &a, vector<int> &b, int &&n) {
    int l = 0;
    int r = n; // OPTIMIZATION: Right bound is n instead of a.size()
    while (l < r) { // binary search to find suitable target

        int aix = l + (r - l) / 2; // aix is picked element index in slice a
        int bix = n - aix - 2; // bix is picked element index in slice b

        if (aix >= a.size() || aix + 1 > n) {
            r = aix;
            continue;
        }

        if (aix + 1 == n) { // if find equal length slice
            return pair<int, int>(aix + 1, 0);
        }

        int abound = aix < a.size() - 1 ? a[aix + 1] : INT64_MAX;
        int bbound = bix < b.size() - 1 ? b[bix + 1] : INT64_MAX;
        if (a[aix] <= bbound && b[bix] <= abound) { //
            return make_pair(aix+1, bix+1);
        }else if (b[bix] > abound) {
            l = aix+1;
        }else { // remain case: a[aix] > bbound
            r = aix;
        }
    }
}

int main() {

    // CASE 1: iter right to find the target in second array
    vector<int> a = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> b = {4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    auto c = divide(a, b, 8);
    // result: 5, 3: means the first 5 of a and first 3 of b
    cout << c.first << " " << c.second << std::endl;


    // CASE 2: try again if do not find appropriate solution in last search
    vector<int> d = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> e = {4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    auto f = divide(d, e, 10);
    // result: 6, 4: means the first 6 of e and first 4 of f
    cout << f.first << " " << f.second << std::endl;


    // CASE 3: all elements in one array
    vector<int> g = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> h = {8, 9, 10, 11, 12};
    auto i = divide(g, h, 8);
    // result: 8, 0: means the first 8 of c and first 0 of d
    cout << i.first << " " << i.second << std::endl;


    // CASE 4: iter left to find the target in second array
    vector<int> j = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> k = {1, 2, 4, 4, 4, 7, 10, 11, 12};
    auto l = divide(j, k, 8);
    // result: 5, 3: means the first 5 of g and first 3 of h
    cout << l.first << " " << l.second << std::endl;


    // CASE 5: element in aa not found in bb, we use backup strategy which is to pick the nearest to target instead
    vector<int> m = {1, 5, 10};
    vector<int> n = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    auto o = divide(m, n, 6);
    // result: 2, 4: means the first 2 of c and first 4 of d
    cout << o.first << " " << o.second << std::endl;

}