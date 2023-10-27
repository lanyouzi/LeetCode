/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-04-16 16:51:54
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-04-16 16:53:07
 * @FilePath: 1147.段式回文.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

// @lc code=start
class Solution {
public:
    int longestDecomposition(string text) {
        // greedy search, find the shortest common segment
        int n = text.size();
        if (n==0) {
            return 0;
        }
        int left = 0, right = n-1;
        while (right>=(n+1)/2) {
            while (right>=(n+1)/2 && text[right]!=text[left]) {
                right--;
            }
            if (right<(n+1)/2) {
                return 1;
            }
            int cur_len = n - right;
            // cout << text << " " << left << " " << right << " " << cur_len << endl;
            if (text.substr(left, cur_len)==text.substr(right, cur_len)) {
                return 2 + longestDecomposition(text.substr(left+cur_len, n-2*cur_len));
            } else {
                right--;
            }
        }
        return 1;

    }
};
// @lc code=end

