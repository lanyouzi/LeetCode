/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

// @lc code=start
class Solution {
   public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) {
            return to_string(nums[0]);
        } else if (nums.size() == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        } else {
            string ans = "";
            for (int i = 0; i < nums.size(); i++) {
                ans += to_string(nums[i]);

                if (i < nums.size() - 1) {
                    ans += "/";
                }
                if (i == 0) {
                    ans += "(";
                }
                if (i == nums.size() - 1) {
                    ans += ")";
                }
            }
            return ans;
        }
    }
};
// @lc code=end
