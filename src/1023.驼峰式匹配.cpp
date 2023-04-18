/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(n, false);
        for (auto &query:queries) {
            int p = 0;
            bool cur = true;
            for (auto& ch:query) {  // 遍历查询串每一个字符
                if (p<pattern.size() && ch==pattern[p]) {   // 字符匹配，模式串指针右移
                    p++;
                } else if (!islower(ch)) {  // 不匹配，且查询串字符非小写，必然无法匹配
                    cur = false;
                    break;
                }
            }
            ans.emplace_back(cur?p==pattern.size():false);
        }
        return ans;
    }
};
// @lc code=end

