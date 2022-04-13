/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
bool cmp(string& a, string& b) {
    if (a.size() == b.size()) {
        return a > b;
    } else {
        return a.size() < b.size();
    }
}
class Solution {
   public:
    string longestWord(vector<string>& words) {
        string ans;
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> st;
        for (auto& word : words) {
            if (word.size() == 1) {
                st.insert(word);
                ans = word;
            } else {
                string prefix = word.substr(0, word.size() - 1);
                if (st.find(prefix) != st.end()) {
                    st.insert(word);
                    ans = word;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
