//
// Created by bowen on 2020/8/19.
//
#include <vector>
#include <iostream>
using namespace std;

// return value is a pair, represent the index in a and b
// to truncate (totally added up to n and no overlap)
pair<int, int> divide(vector<int> a, vector<int> b, int n) {
    int l = 0;
    int r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;

        // detect duplicate
        while (mid < a.size() - 1 && a[mid] == a[mid+1]) {
            mid++;
        }

        // if the index already larger than n
        if (mid > n) {
            r = mid;
            continue;
        }

        // if the index equal n
        if (mid == n) {
            return pair<int, int>(mid, 0);
        }

        // target value for b to search
        int targetB = a[mid];
        int ll = 0;
        int rr = n;

        // find the pos in B
        while (ll < rr) {
            int mmid = ll + (rr - ll) / 2;
            if (b[mmid] < targetB) {
                ll = mmid+1;
            }else if (b[mmid] > targetB) {
                rr = mmid;
            } else{
                // find the value
                // detect duplicate
                int premain = mmid;
                while (premain < b.size() - 1 && b[premain] == b[premain+1]) {
                    premain++;
                }

                // if it is added up to n
                if (premain + mid == n){
                    return pair<int, int>(mid, premain);
                }else{

                    // otherwise adjust the bound
                    if (premain + mid < n) {
                        l = mid;
                    }else if (premain + mid > n) {
                        r = mid;
                    }
                    break;
                }
            }
        }

        // if we didnt find the targetB in B because targetB is too large
        if (targetB > b.back()) {
            r = mid;
        } else if (targetB < b[0]) { // or too small
            l = mid+1;
        }
    }

}

int main() {
    vector<int> a = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> b = {4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    auto i = divide(a, b, 8);
    // result: 5, 3: means the first 5 of a and first 3 of b
    cout << i.first << " " << i.second << std::endl;

    vector<int> c = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> d = {8, 9, 10, 11, 12};
    auto j = divide(c, d, 8);
    // result: 8, 0: means the first 8 of a and first 0 of b
    cout << j.first << " " << j.second << std::endl;
}