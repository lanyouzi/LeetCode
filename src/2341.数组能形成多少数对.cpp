/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> v(101, 0);
        int pairings = 0;
        for (auto& num:nums) {
            v[num]++;
        }
        for (int i=0; i<=100; i++) {
            pairings+=(v[i]/2);
        }
        vector<int> ans = {pairings, (int)nums.size()-2*pairings};
        return ans;

    }
};
// @lc code=end

