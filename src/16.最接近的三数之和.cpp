/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

// double-pointer
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 1; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int value = nums[i] + nums[left] + nums[right];
                if (abs(value - target) < abs(ans - target)) {
                    ans = value;
                }
                if (value < target) {
                    left++;
                } else if (value > target) {
                    right--;
                } else {
                    return target;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
