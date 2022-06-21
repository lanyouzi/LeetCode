/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (auto ch:address) {
            if (ch=='.') {
                ans+="[.]";
            } else {
                ans+=ch;
            }
        }
        return ans;
    }
};
// @lc code=end

