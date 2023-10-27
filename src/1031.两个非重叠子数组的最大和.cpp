/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-04-26 13:21:45
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-04-26 13:21:56
 * @FilePath: 1031.两个非重叠子数组的最大和.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size(), max_val = 0;
        vector<int> ps(n+1, 0);
        for (int i=1; i<=n; i++) {
            ps[i] = ps[i-1]+nums[i-1];
        }
        for (int i=firstLen; i<=n; i++) {
            for (int j=secondLen; j<=n; j++) {
                if (i<j-secondLen+1 || i-firstLen+1>j) {
                    max_val = max(max_val, ps[i]-ps[i-firstLen]+ps[j]-ps[j-secondLen]);
                }
            }
        }
        return max_val;  
    }
};
// @lc code=end

