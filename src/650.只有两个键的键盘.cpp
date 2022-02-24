/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
   public:
    //质因数之和
    int minSteps(int n) {
        int res = 0;
        for (auto i = 2; i <= n; i++) {
            if (n % i == 0) {
                n = n / i;
                res += i;
                i--;
            }
        }
        if (n > 1) {
            res += n;
        }
        return res;
    }
};
// @lc code=end
