/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-11 13:29:21
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-11 13:29:32
 * @FilePath: 135.分发糖果.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int> prefix(n, 1), suffix(n, 1);
        for (int i=1; i<n; i++) {
            prefix[i] = ratings[i]>ratings[i-1]?prefix[i-1]+1:1;
        }
        for (int i=n-2; i>=0; i--) {
            suffix[i] = ratings[i]>ratings[i+1]?suffix[i+1]+1:1;
        }
        for (int i=0; i<n; i++) {
            ans+=max(prefix[i], suffix[i]);
        }
        return ans;
    }
};
// @lc code=end

