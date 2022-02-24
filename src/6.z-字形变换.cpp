/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
string convert(string s, int numRows) {
    if (numRows==1) {
        return s;
    }
    string ans = "";
    int span = 2 * numRows - 2;
    for (int i = 0; i < numRows; i++) {
        int ci = i;
        int flag = -2 * i + span;
        while (ci < s.size()) {
            ans += s[ci];
            if (flag % span != 0 && ci + flag < s.size()) {
                ans += s[ci + flag];
            }
            ci = ci + span;
        }
    }
    return ans;
}
};
// @lc code=end

