/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
   public:
    bool isPowerOfThree(int n) {
        if (n == 1) {
            return true;
        }
        if (n > 0 && n % 3 == 0) {
            return isPowerOfThree(n / 3);
        }
        return false;
    }
};
// @lc code=end
