#include <bits/stdc++.h>
using namespace std;

int binary_saerch(vector<int> &v, int target, int l, int r) {
    if (l>=r) {
        return -1;
    }
    int mid = (l+r)/2;
    if (v[mid]==target) {
        return mid;
    } else if (v[mid]<target) {
        return binary_saerch(v, target, mid+1, r);
    } else {
        return binary_saerch(v, target, l, mid-1);
    }
}

int main() {
    vector<int> v = {1, 4, 7, 9, 11, 16};
    cout << binary_saerch(v, 7, 0, 5);
    return 0;
}