/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
   public:
    set<vector<int>> st;
    void perm(vector<int>& nums, int i) {
        if (i == nums.size() - 1) {
            vector<int> v = nums;
            st.insert(v);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            perm(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        perm(nums, 0);
        vector<vector<int>> ans;
        ans.assign(st.begin(), st.end());
        return ans;
    }
};
// @lc code=end
