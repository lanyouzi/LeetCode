/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution {
   public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> index;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                index.emplace_back(i);
            }
        }
        int n = s.size();
        index.emplace_back(INT_MAX);
        int ci = 0;
        for (int i = 0; i < n; i++) {
            int x = abs(i - index[ci]), y = abs(i - index[ci + 1]);
            if (x <= y) {
                ans.emplace_back(x);
            } else {
                ci++;
                ans.emplace_back(y);
            }
        }
        return ans;
    }
};
// @lc code=end
