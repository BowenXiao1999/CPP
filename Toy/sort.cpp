//
// Created by bowen on 2020/8/19.
//
#include <vector>
#include <iostream>
using namespace std;

// return value is a pair, represent the truncated slice index in a and b
pair<int, int> divide(vector<int> &a, vector<int> &b, int &&n) {
    int l = 0;
    int r = n; // OPTIMIZATION: Right bound is n instead of a.size()
    while (l < r) { // binary search to find suitable target
        int mid = l + (r - l) / 2;
        int mmid = n - mid - 2;
        if (mid >= a.size() || mid + 1 > n) {
            r = mid;
            continue;
        }

        if (mid + 1 == n) { // if find equal length slice
            return pair<int, int>(mid + 1, 0);
        }

        // target value for b to search
        int targetB = a[mid];

        // [OPTIMIZATION] BOUNDARY CASE: if targetB is larger than any ele in B
        if (targetB > b.back()) {
            r = mid;
            continue;
        } else if (targetB < b[0]) { // or too small
            l = mid + 1;
            continue;
        }
        if (mid < a.size() - 1 && mmid < b.size() - 1){
            if (a[mid] <= b[mmid + 1] && b[mmid] <= a[mid+1]) {
                return make_pair(mid+1, mmid+1);
            }else if (a[mid] < b[mmid]) {
                l = mid+1;
            }else if (a[mid] > b[mmid+1])  {
                r = mid;
            }
        }
    }
}

    // return value is a pair, represent the truncated slice index in a and b
//pair<int, int> divide(vector<int> &a, vector<int> &b, int &&n) {
//    int l = 0;
//    int r = n; // OPTIMIZATION: Right bound is n instead of a.size()
//    while (l < r) { // binary search to find suitable target
//        int mid = l + (r - l) / 2;
//        if (mid >= a.size()) {
//            r = mid;
//            continue;
//        }
//
//        if (mid + 1 > n) { // if slice larger than n already
//            r = mid;
//            continue;
//        }
//
//
//        if (mid + 1 == n) { // if find equal length slice
//            return pair<int, int>(mid + 1, 0);
//        }
//
//        // target value for b to search
//        int targetB = a[mid];
//
//        // [OPTIMIZATION] BOUNDARY CASE: if targetB is larger than any ele in B
//        if (targetB > b.back()) {
//            r = mid;
//            continue;
//        } else if (targetB < b[0]) { // or too small
//            l = mid + 1;
//            continue;
//        }
//
//        // locate targetB in B via Binary Search
//        int ll = 0;
//        int rr = n - mid - 2; // OPTIMIZATION: we only need to locate targetB in remain interval
//        if (b[rr] == targetB) {
//            return make_pair(mid + 1, rr + 1);
//        } else if (b[n-mid] < targetB){
//            r = mid;
//        }else{
//            l = mid+1;
//        }
//    }
//        bool isfound = false; int backup = -1; // OPTIMIZATION: for backup case
//        while (ll < rr) { // search begin
//            int mmid = ll + (rr - ll) / 2;
//
//            if (b[mmid] < targetB) {
//                ll = mmid + 1;
//                if (backup == -1 || b[mmid] - targetB > b[backup] - targetB) backup = mmid; // find the cloest neighbour to targetB
//            } else if (b[mmid] > targetB) {
//                rr = mmid;
//            } else {
//                isfound = true; // find target
//                int premain = mmid;
//                while (premain < b.size() && premain >= 0) { // duplicate detection
//                    if (premain + mid + 2 == n) { // if it is added up to n
//                        return pair<int, int>(mid+1, premain+1);
//                    } else {
//
//                        // otherwise adjust the bound
//                        if (premain + mid + 2 < n) {
//                            if (premain < b.size() - 1 && b[premain] != b[premain+1]) break;
//                            premain++; // iter right to check
//                        } else if (premain + mid + 2 > n) {
//                            if (premain > 0 && b[premain] != b[premain-1]) break;
//                            premain--; // iter left to check
//                        }
//                    }
//                }
//
//                // still not satisfy the n number
//                if (premain + mid + 2 < n) {
//                    l = mid + 1;
//                } else if (premain + mid + 2 > n) {
//                    r = mid;
//                }
//                break;
//            }
//
//        }
//
//        // if we don't find any targetB in B, adjust the bound in A by backup
//        if (!isfound){
//            if (backup + mid + 2 < n){
//                l = mid + 1;
//            } else if (backup + mid + 2 > n){
//                r = mid;
//            }else {
//                return make_pair(mid+1, backup+1);
//            }
//        }
//    }

    // if we did not find qualify result
//    return make_pair(-1, -1);
//}

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