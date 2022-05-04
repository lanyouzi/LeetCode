/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (right > left) {
            if (nums[right] % 2 == 0) {
                swap(nums[left], nums[right]);
                left++;
            } else {
                right--;
            }
        }
        return nums;
    }
};
// @lc code=end
