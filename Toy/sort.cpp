//
// Created by bowen on 2020/8/19.
//
#include <vector>
#include <iostream>
using namespace std;

// return value is a pair, represent the truncated slice in a and b
pair<int, int> divide(vector<int> a, vector<int> b, int n) {
    int l = 0;
    int r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (mid >= a.size()) {
            r = mid;
            continue;
        }
        // if the index already larger than n
        if (mid + 1> n) {
            r = mid;
            continue;
        }

        // if the index equal n
        if (mid + 1 == n) {
            return pair<int, int>(mid+1, 0);
        }

        // target value for b to search
        int targetB = a[mid];

        // if not find the targetB in B because targetB is too large
        if (targetB > b.back()) {
            r = mid;
            continue;
        } else if (targetB < b[0]) { // or too small
            l = mid+1;
            continue;
        }

        // locate targetB in B via Binary Search
        int ll = 0;
        int rr = n;
        bool isfound = false;
        int backup = INT64_MIN;
        while (ll < rr) {
            int mmid = ll + (rr - ll) / 2;

            if (b[mmid] < targetB) {
                ll = mmid + 1;
                if (b[mmid] - targetB > backup - targetB) backup = max(backup, mmid);
//                continue;
            } else if (b[mmid] > targetB) {
                rr = mmid;
//                continue;
            } else {
                isfound = true;
                // find the value but still need duplicate detection
                int premain = mmid;
                while (premain < b.size() && premain >= 0) {
                    // if it is added up to n
                    if (premain + mid + 2 == n) {
                        return pair<int, int>(mid+1, premain+1);
                    } else {

                        // otherwise adjust the bound
                        if (premain + mid + 2 < n) {
                            if (premain < b.size() - 1 && b[premain] != b[premain+1]) break;
                            premain++;
                        } else if (premain + mid + 2 > n) {
                            if (premain > 0 && b[premain] != b[premain-1]) break;
                            premain--;
                        }
                    }
                }

                if (premain + mid + 2 < n) {
                    l = mid + 1;
                } else if (premain + mid + 2 > n) {
                    r = mid;
                }
                break;
            }

        }
        // if we don't find any targetB in B, adjust the bound in A
        if (!isfound){
            // not find the back up
            if (backup + mid + 2 < n){
                l = mid + 1;
            } else if (backup + mid + 2 > n){
                r = mid;
            }else {
                return make_pair(mid+1, backup+1);
            }
        }
    }

    // if we did not find qualify result
    return make_pair(-1, -1);
}

int main() {

    // CASE 1: iter right to find the target in second array
    vector<int> a = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> b = {4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    auto i = divide(a, b, 8);
    // result: 5, 3: means the first 5 of a and first 3 of b
    cout << i.first << " " << i.second << std::endl;


    // CASE 2: try again if do not find appropriate solution in last search
    vector<int> e = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> f = {4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    auto k = divide(e, f, 10);
    // result: 6, 4: means the first 6 of e and first 4 of f
    cout << k.first << " " << k.second << std::endl;


    // CASE 3: all elements in one array
    vector<int> c = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> d = {8, 9, 10, 11, 12};
    auto j = divide(c, d, 8);
    // result: 8, 0: means the first 8 of c and first 0 of d
    cout << j.first << " " << j.second << std::endl;


    // CASE 4: iter left to find the target in second array
    vector<int> g = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    vector<int> h = {1, 2, 4, 4, 4, 7, 10, 11, 12};
    auto l = divide(g, h, 8);
    // result: 5, 3: means the first 5 of g and first 3 of h
    cout << l.first << " " << l.second << std::endl;


    // CASE 5: element in aa not found in bb, we use backup strategy which is to pick the nearest to target instead
    vector<int> aa = {1, 5, 10};
    vector<int> bb = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    auto cc = divide(aa, bb, 6);
    // result: 2, 4: means the first 2 of c and first 4 of d
    cout << cc.first << " " << cc.second << std::endl;

}