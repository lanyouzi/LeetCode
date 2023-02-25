/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        int index = 0;
        for (int i=0; i<(1<<n); i++) {
            ans.emplace_back(start^i^(i>>1));
        }
        return ans;
    }
};
// @lc code=end

