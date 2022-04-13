/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution {
   public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int rows = 1, p = 0;
        for (auto& ch : s) {
            if (p + widths[ch - 'a'] <= 100) {
                p += widths[ch - 'a'];
            } else {
                rows++;
                p = widths[ch - 'a'];
            }
        }
        return {rows, p};
    }
};
// @lc code=end
