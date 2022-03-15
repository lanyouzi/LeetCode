/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
   public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string ans = "";
        bool is_positive = true;
        if (num < 0) {
            is_positive = false;
            num = abs(num);
        }
        while (num > 0) {
            int tmp = num % 7;
            ans = to_string(tmp) + ans;
            num /= 7;
        }
        if (!is_positive) {
            ans = '-' + ans;
        }
        return ans;
    }
};
// @lc code=end
