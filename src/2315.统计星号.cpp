/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

// @lc code=start
class Solution {
public:
    int countAsterisks(string s) {
        bool flag = false;  // check if in pairs
        int ans = 0;
        for (int i=0; i<s.size(); i++) {
            if (!flag && s[i]=='*') {
                ans++;
            } else if (s[i]=='|') {
                flag = !flag;
            }
        }
        return ans;
    }
};
// @lc code=end

