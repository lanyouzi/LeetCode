/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-08 14:59:22
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-08 14:59:30
 * @FilePath: 438.找到字符串中所有字母异位词.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> need;
        int n = s.size(), m = p.size();
        int left = 0, right = 0;    // [left, right)
        vector<int> ans;
        for (auto& ch:p) {
            need[ch]++;
        }
        while (right<n) {
            // cout << left << " " << right << endl;
            // 向右扩张
            if (--need[s[right]]==0) {
                need.erase(s[right]);
            }
            right++; 
            if (right-left>m) {
                if (++need[s[left]]==0) {
                    need.erase(s[left]);
                }
                left++;
            }
            if (need.empty()) {
                ans.emplace_back(left);
            }
            
        }
        return ans;
    }
};
// @lc code=end

