/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 */

// @lc code=start
class Solution {
   public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1;
        int lower = upper;
        while (lower--) {
            // construct palindorme p
            long long p = lower;
            for (int x = lower; x > 0; x /= 10) {
                p = 10 * p + x % 10;
            }
            for (int i = upper; i >= sqrt(p); i--) {
                if (p % i == 0) {
                    return p % 1337;
                }
            }
        }
        return 0;
    }
};
// @lc code=end
