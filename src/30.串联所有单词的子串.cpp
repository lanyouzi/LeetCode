/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> mp1;
        map<string, int> mp2;
        vector<int> ans;
        int word_size = words[0].size();
        int n = words.size() * word_size;
        for (auto& word : words) {
            mp1[word] += 1;
        }
        for (int i = 0; i + n <= s.size(); i++) {
            mp2.clear();
            string substr = s.substr(i, n);
            int j;
            for (j = 0; j + word_size <= substr.size(); j += word_size) {
                string cword = substr.substr(j, word_size);
                mp2[cword] += 1;
                if (mp2[cword] > mp1[cword]) {
                    break;
                }
            }
            if (j == substr.size()) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end
