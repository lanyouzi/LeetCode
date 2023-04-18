/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer Moore Algorithm
        int ans = nums[0], cnt = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            if (cnt==0) {
                ans = nums[i];
            }
            if (nums[i]==ans) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ans;
    }
};
// @lc code=end

