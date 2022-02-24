/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    k = min(k, nums.size()-1);
    for (int i=1; i<=k; i++) {
        for (int j=0; j<nums.size()-i; j++) {
            if (nums[j]==nums[j+i]) {
                return true;
            }
        }
    }
    return false;
}
};
// @lc code=end

