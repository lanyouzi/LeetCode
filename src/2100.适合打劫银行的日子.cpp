/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
   public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> left(security.size(), 0);
        vector<int> right(security.size(), 0);
        vector<int> ans;
        for (int i = 1; i < security.size(); i++) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = security.size() - 1; i > 0; i--) {
            if (security[i - 1] <= security[i]) {
                right[i - 1] = right[i] + 1;
            }
        }

        for (int i = time; i + time < security.size(); i++) {
            if (left[i] >= time && right[i] >= time) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end
