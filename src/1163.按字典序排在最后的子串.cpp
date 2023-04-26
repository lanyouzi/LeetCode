/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 *
 * [1163] 按字典序排在最后的子串
 */

// @lc code=start
class Solution {
public:
    string lastSubstring(string s) {
         // double pointers
        int i = 0, k = 0, n = s.size();
        for (int j=1; j+k<n;) {
            if (s[i+k]==s[j+k]) {
                k++;
            } else if (s[i+k]<s[j+k]) {
                i += k + 1;
                k = 0;
                if (i>=j) {
                    j = i + 1;
                }

            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
// @lc code=end

