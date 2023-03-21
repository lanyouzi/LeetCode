/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mp;
        vector<int> flag(strs.size(), 0);
        int group = 0;
        for (int i=0; i<strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (mp.count(tmp)==0) {
                mp[tmp] = group++;
            }
            flag[i] = mp[tmp];
        }
        vector<vector<string>> ans(group);
        for (int i=0; i<strs.size(); i++) {
            ans[flag[i]].emplace_back(strs[i]);
        }
        return ans;
    }
};
// @lc code=end

