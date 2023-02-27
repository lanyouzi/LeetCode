/*
 * @lc app=leetcode.cn id=1255 lang=cpp
 *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26);      // number of letters available
        int n = words.size();
        int ans = 0;
        for (auto& letter:letters) {
            count[letter-'a']++;
        }
        for (int flag=1; flag<(1<<n); flag++) {
            vector<int> cur_count(26);
            bool is_legal = true;
            for (int i = 0; i < n; i++) {   // traverse all words
                if ((flag & (1<<i)) == 0 || !is_legal) {
                    continue;
                }
                for (auto& ch:words[i]) {
                    cur_count[ch-'a']++;
                    if (cur_count[ch-'a']>count[ch-'a']) {
                        is_legal = false;
                        break;
                    }
                }
            }
            if (is_legal) {
                int sum = 0;
                for (int i=0; i<26; i++) {
                    sum+=score[i]*cur_count[i];
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
// @lc code=end

