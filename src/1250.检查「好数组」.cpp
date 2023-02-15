/*
 * @lc app=leetcode.cn id=1250 lang=cpp
 *
 * [1250] 检查「好数组」
 */

// @lc code=start
class Solution {
public:
    // 裴蜀定理，判断是否存在子序列的gcd为1
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int i=0; i<nums.size(); i++) {
            g = gcd(g, nums[i]);
            if (g==1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

