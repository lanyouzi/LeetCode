/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
   public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        vector<int> ans(n + 1, 0);
        vector<int> tmp(n + 1, 0);
        ans[0] = 1;
        ans[1] = 10;
        tmp[1] = 9;
        for (int i = 2; i <= n; i++) {
            tmp[i] = tmp[i - 1] * (11 - i);
            ans[i] = ans[i - 1] + tmp[i];
        }
        return ans[n];
    }
};
// @lc code=end
