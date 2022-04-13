/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
   public:
    int slicing_window(vector<int>& nums, int k, int p) {
        int left = 0, right = 0;
        int sum = 0;
        int ans = 0;
        while (right < nums.size()) {
            if (nums[right] != p) {
                sum++;
            }
            if (sum > k) {
                if (nums[left] != p) {
                    sum--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
    int longestOnes(vector<int>& nums, int k) {
        return slicing_window(nums, k, 1);
    }
};
// @lc code=end
