/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
class Solution {
public:
    // greedy search
    int getMaximumConsecutive(vector<int>& coins) {
        int ans = 1;
        sort(coins.begin(), coins.end());
        for (auto& coin : coins) {
            if (coin > ans) {
                break;
            }
            ans += coin;
        }
        return ans;
    }
};
// @lc code=end

