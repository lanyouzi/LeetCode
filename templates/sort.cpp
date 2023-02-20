/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-15 17:03:29
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-15 20:29:07
 * @FilePath: \LeetCode\templates\sort.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &v, int l, int r) {
    if (l>=r) {
        return;
    }
    int i = l, j = r;
    int target = v[i];
    while (i<j) {
        if (v[i])
    }
    quicksort(v, l, i-1);
    quicksort(v, i+1, r);

    
}
int main() {
    vector<int> v = {2, 5, 7, 1, 8};
    // quicksort(v, 0, v.size()-1);
    for (auto &item:v) {
        cout << item << " ";
    }
}