/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> ans;
    void perm(vector<int>& nums, int i) {
        if (i == nums.size() - 1) {
            vector<int> v = nums;
            ans.emplace_back(v);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            perm(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0);
        return ans;
    }
};
// @lc code=end
