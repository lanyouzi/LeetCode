/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        vector<vector<int>> ans;
        for (auto& item:items1) {
            if (mp.count(item[0])) {
                mp[item[0]]+=item[1];
            } else {
                mp[item[0]]=item[1];
            }
        }
        for (auto& item:items2) {
            if (mp.count(item[0])) {
                mp[item[0]]+=item[1];
            } else {
                mp[item[0]]=item[1];
            }
        }
        for (auto& item:mp) {
            ans.emplace_back(move(vector<int>{item.first, item.second}));
        }
        return ans;
    }
};
// @lc code=end

