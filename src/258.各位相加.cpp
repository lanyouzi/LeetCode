/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        while(num>9) {
            string s = to_string(num);
            int sum = 0;
            for (auto& digit:s) {
                sum += (digit-'0');
            }
            num = sum;
        }
        return num;
    }
};
// @lc code=end

