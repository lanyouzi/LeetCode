/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> flag(26, -1);
        int cnt = 0;
        string ans;
        for (int i=0; i<key.size(); i++) {
            if (key[i]!=' ' && flag[key[i]-'a']==-1) {
                flag[key[i]-'a']= cnt;
                cnt++;
            }
        }
        for (int i=0; i<message.size(); i++) {
            if (message[i]!=' ') {
                ans+=('a'+flag[message[i]-'a']);
            } else {
                ans+=' ';
            }
        }
        return ans;
    }
};
// @lc code=end

