/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-05-04 11:28:31
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-05-04 11:28:38
 * @FilePath: 2106.摘水果.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] 摘水果
 */

// @lc code=start
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefix_sum(n+1);    // amount 前缀和，下标从0~n
        vector<int> indices(n);
        for (int i=0; i<n; i++) {
            prefix_sum[i+1] = prefix_sum[i]+fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        int left, right, start, end;
        for(int x=0; x<=k/2; x++) {
            // 先往左走x步，再往右走k-2x步
            left = startPos - x;
            right = startPos + k - 2*x;
            start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
            end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, prefix_sum[end]-prefix_sum[start]);
            
            // 先往右走x步，再往左走k-2x步
            right = startPos + x;
            left = startPos - k + 2*x;
            start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
            end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, prefix_sum[end]-prefix_sum[start]);
        }
        return ans;
    }
};
// @lc code=end

