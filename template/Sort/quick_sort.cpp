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

void quick_sort(vector<int> &v, int l, int r) {
    if (l>=r) {
        return;
    }
    int i = l, j = r;
    while (i<j) {
        if (v[i]>v[j]) {
            swap(v[i], v[j]);
            i++;
        } else {
            j--;
        }
    }
    quick_sort(v, l, i-1);
    quick_sort(v, i+1, r);
}
