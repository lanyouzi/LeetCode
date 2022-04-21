/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxw = 0;
        for (auto& person:accounts) {
            int w = 0;
            for (auto &bank:person) {
                w+=bank;
            }
            if (w>maxw) {
                maxw = w;
            }
        }
        return maxw;
    }
};
// @lc code=end

