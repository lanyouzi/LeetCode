/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-20 11:27:36
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-20 11:32:23
 * @FilePath: \LeetCode\src\567.字符串的排列.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> need(26, 0);
        for (auto& ch : s1) {
            need[ch - 'a']++;
        }
        int left = 0, right = 0;
        while (right < m) {
            int x = s2[right] - 'a';
            need[x]--;
            //保证每次进来的右指针所代表的字符恰好满足要求
            while (need[x] < 0) {
                need[s2[left] - 'a']++;
                left++;
            }
            // 如果当前串长度等于s1，则说明合法
            if (right - left + 1 == n) {
                return true;
            }
            right++;
        }
        return false;
    }
};
// @lc code=end

