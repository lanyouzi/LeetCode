/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int flag = 0, tmp = 0,
            ans = 0;  // flag起始位置，tmp当前结果，ans最优结果
        set<char> st; // 用以判定字符是否出现
        while (flag + tmp < s.size()) {
            if (st.find(s[flag + tmp]) == st.end()) {
                st.insert(s[flag + tmp]);
                tmp++;
                ans = max(tmp, ans);
            } else {
                st.erase(s[flag]);
                flag++;
                tmp--;
            }
        }
        return ans;
    }
};
// @lc code=end
