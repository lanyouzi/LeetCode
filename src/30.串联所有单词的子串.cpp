/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> need;
        vector<int> ans;
        int word_size = words[0].size();
        int need_size = words.size() * word_size;
        int n = s.size();
        for (auto& word : words) {
            need[word] ++;
        }
        for (int i=0; i<word_size && i+need_size<=n; i++) {
            map<string, int> cur = need;
            int left = i, right = i;
            while (right+word_size<=n) {
                string cword;
                if (right-left >= need_size) {      // 收缩左端点
                    cword = s.substr(left, word_size);
                    cur[cword]++;
                    if (cur[cword]==0) {
                        cur.erase(cword);
                }
                    left+=word_size;
                }
                cword = s.substr(right, word_size); // 扩张右端点
                right+=word_size;
                cur[cword]--;
                if (cur[cword]==0) {
                    cur.erase(cword);
                }
                if (cur.empty()) {
                    ans.emplace_back(left);
                }
                
            }
        }
        return ans;
    }
};
// @lc code=end
