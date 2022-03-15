/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

/*
区间dp，遍历时记录最大和最小值，时间复杂度为O(n^2) 
 */

// @lc code=start
class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int min_num = INT_MAX, max_num = INT_MIN;
            for (int j = i; j < nums.size(); j++) {
                min_num = min(min_num, nums[j]);
                max_num = max(max_num, nums[j]);
                ans += max_num - min_num;
            }
        }
        return ans;
    }
};
// @lc code=end
