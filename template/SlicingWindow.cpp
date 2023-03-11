/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-08 14:09:52
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-10 14:31:58
 * @FilePath: SlicingWindow.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;

/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    
    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // 右指针移动，c是将移入窗口的字符
        char c = s[right++];

        // 进行窗口内数据的一系列更新

        // TODO
        // ...

        
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // 左移窗口，d是将移出窗口的字符
            char d = s[left++];
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
int main() {
    return 0;
}