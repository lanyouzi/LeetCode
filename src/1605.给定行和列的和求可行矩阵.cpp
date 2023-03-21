/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-14 10:23:18
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-14 10:23:23
 * @FilePath: 1605.给定行和列的和求可行矩阵.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rowSum[i] == 0) {
                    break;
                }
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end
