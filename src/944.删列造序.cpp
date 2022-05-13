/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            int cnum = 0;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] < cnum) {
                    ans++;
                    break;
                }
                cnum = strs[j][i];
            }
        }
        return ans;
    }
};
// @lc code=end
