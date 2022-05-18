/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
map<char, int> mp;
bool cmp(string& s1, string& s2) {
    int i = 0;
    for (i = 0; i < min(s1.size(), s2.size()); i++) {
        if (s1[i] != s2[i]) {
            return mp[s1[i]] < mp[s2[i]];
        }
    }
    return s1.size() < s2.size();
}
class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        vector<string> origin = words;
        sort(words.begin(), words.end(), cmp);
        for (int i = 0; i < words.size(); i++) {
            if (origin[i] != words[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
