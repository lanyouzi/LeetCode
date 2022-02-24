/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> se;
        set<string> se_ans;
        vector<string> ve_ans;
        if (s.length() < 10) {
            return ve_ans;
        }
        for (auto i = 0; i < s.length() - 9; i++) {
            cout << s.substr(i, 10) << endl;
            if (se.find(s.substr(i, 10)) == se.end()) {
                se.insert(s.substr(i, 10));
            } else {
                se_ans.insert(s.substr(i, 10));
            }
        }
        ve_ans.assign(se_ans.begin(), se_ans.end());
        return ve_ans;
    }
};
// @lc code=end
