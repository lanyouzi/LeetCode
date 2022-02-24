/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
   public:
    string toHex(int num) {
        long long lnum = num;
        if (num == 0) {
            return "0";
        } else if (lnum < 0) {
            lnum += pow(2, 32);
        }
        vector<char> v;
        while (lnum > 0) {
            int tmp = lnum % 16;
            if (tmp < 10) {
                v.emplace_back('0' + tmp);
            } else {
                v.emplace_back('a' + (tmp - 10));
            }
            lnum = lnum / 16;
        }
        reverse(v.begin(), v.end());
        string ans = "";
        for (auto& item : v) {
            ans += item;
        }
        return ans;
    }
};
// @lc code=end
