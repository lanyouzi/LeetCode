/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
   public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> flag(30);
        fill(flag.begin(), flag.end(), 0);
        int num = 0;
        string ans = "";
        for (auto& ch : licensePlate) {
            if (isalpha(ch)) {
                flag[tolower(ch) - 'a']++;
                if (flag[tolower(ch) - 'a'] == 1) {
                    num++;
                }
            }
        }
        // cout << num << endl;
        for (auto& word : words) {
            vector<int> tmp = flag;
            int r = num;
            for (auto& ch : word) {
                tmp[tolower(ch) - 'a']--;
                if (tmp[tolower(ch) - 'a'] == 0) {
                    r--;
                }
            }
            if (r == 0 && (ans.length() == 0 || word.length() < ans.length())) {
                ans = word;
            }
        }
        return ans;
    }
};
// @lc code=end
