/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (auto c : s) {
            stk.push_back(c);
            if (stk.size() >= 3 && stk.substr(stk.size() - 3, 3) == "abc") {
                stk.erase(stk.end() - 3, stk.end());
            }
        }
        return stk.empty();
    }
};
// @lc code=end

