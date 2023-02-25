/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-21 12:53:32
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-21 12:53:38
 * @FilePath: \LeetCode\src\1326.灌溉花园的最少水龙头数目.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

// @lc code=start
class Solution {
public:
    // greedy strategy
    int minTaps(int n, vector<int>& ranges) {
        int ans = 0;
        int left, right;
        vector<int> flag(n+1, 0);
        for (int i=0; i<=n; i++) {
            left = max(i-ranges[i], 0);
            right = min(i+ranges[i], n);
            flag[left] = max(flag[left], right);
        }
        int longest = 0, pre = 0;
        for (int i=0; i<n; i++) {
            longest = max(longest, flag[i]);
            if (longest == i) {    // 索引i的水龙头为不可往右
                return -1;
            }
            if (pre == i) {          // 上一个区间已经用完
                pre = longest;
                ans ++;
            }
        }
        return ans;
    }
};
// @lc code=end

