/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

/*
    找到下标i, j满足nums[i]<nums[j]，同时nums[i]尽可能靠右，nums[j]尽可能小
    交换二者位置，并将较小数右边部分按从小到大顺序重新排列。
 */
// @lc code=start
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int left, right;
        for (left = nums.size() - 2; left >= 0; left--) {
            if (nums[left] < nums[left + 1]) {
                break;
            }
        }
        if (left < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        for (right = left + 1; right < nums.size(); right++) {
            if (nums[right] <= nums[left]) {
                break;
            }
        }
        right--;
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        sort(nums.begin() + left + 1, nums.end());
    }
};
// @lc code=end
