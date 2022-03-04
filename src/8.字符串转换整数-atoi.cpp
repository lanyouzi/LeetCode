/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
   public:
    int myAtoi(string s) {
        long long ans = 0;
        bool is_positive = true;
        int index = 0;
        while (s[index] == ' ') {
            index++;
        }
        if (s[index] == '-') {
            is_positive = false;
            index++;
        } else if (s[index] == '+') {
            index++;
        }
        while (s[index] == '0') {
            index++;
        }
        int begin = index;
        while (index < s.size() && isdigit(s[index])) {
            index++;
        }
        if (index - begin > 10) {
            if (is_positive) {
                return pow(2, 31) - 1;
            } else {
                return -pow(2, 31);
            }
        }
        for (int i = index - 1; i >= begin; i--) {
            long long tmp = (s[i] - '0') * pow(10, index - 1 - i);
            ans += tmp;
            if (ans > pow(2, 31) - 1 && is_positive) {
                return pow(2, 31) - 1;
            } else if (ans > pow(2, 31) && !is_positive) {
                return -pow(2, 31);
            }
        }
        if (is_positive) {
            return ans;
        } else {
            return -ans;
        }
    }
};
// @lc code=end
