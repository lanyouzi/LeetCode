/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int binary_search(vector<int> &nums, int target, bool geq) {
        int left = 0, right = nums.size()-1;
        int ans = nums.size();
        while (left<=right) {
            int mid = (left+right)/2;
            if (nums[mid]>target || (geq && nums[mid]==target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = binary_search(nums, target, true), right = binary_search(nums, target, false);
        if (left>=0 && left<n && nums[left]==target) {
            return {left, right-1};
        }
        return {-1, -1};
    }
};
// @lc code=end

