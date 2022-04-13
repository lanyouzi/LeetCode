/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
   public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            s = s.substr(1, s.size() - 1) + s[0];
            if (s == goal) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
