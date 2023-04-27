/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-04-27 17:31:24
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-04-27 17:31:30
 * @FilePath: 1048.最长字符串链.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size()<b.size();
        });
        map<string, int> mp;
        int ans = 0;
        for (auto& word:words) {
            mp[word] = 1;
            for (int i=0; i<word.size(); i++) {
                string cur = word.substr(0, i) + word.substr(i+1);
                if (mp.count(cur)) {
                    mp[word] = max(mp[word], mp[cur]+1);
                }
            }
            ans = max(ans, mp[word]);
        }
        return ans;
    }
};
// @lc code=end

