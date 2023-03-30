/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-29 13:54:19
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-29 13:54:29
 * @FilePath: 1642.可以到达的最远建筑.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for (int i=0; i<5; i++) {
            dp[1][i] = 1;
        }
        for (int i=2; i<=n; i++) {
            for (int j=0; j<5; j++) {
                for (int k=j; k<5; k++) {
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0);
    }
};
// @lc code=end

