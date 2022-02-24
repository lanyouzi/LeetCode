/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution {
public:
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    vector<int> ans(quiet.size());
    vector<set<int> > rich_idx(quiet.size(), set<int>());
    vector<set<int> > poor_idx(quiet.size(), set<int>());
    for (int i=0; i<quiet.size(); i++) {
        rich_idx[i].insert(i);
        poor_idx[i].insert(i);
        ans[i] = i;
    }

    for (auto rich : richer) {
        rich_idx[rich[0]].insert(rich[1]);
        poor_idx[rich[1]].insert(rich[0]);
        for (auto& item:rich_idx[rich[1]]) {
            rich_idx[rich[0]].insert(item);
        }
        for (auto& item:poor_idx[rich[0]]) {
            poor_idx[rich[1]].insert(item);
        }
        for (auto& item:rich_idx[rich[0]]) {
            if(quiet[rich[0]]<quiet[ans[item]]) {
                ans[item]=rich[0];
            }
        }
        for (auto& item:poor_idx[rich[1]]) {
            if(quiet[item]<quiet[ans[rich[1]]]) {
                ans[rich[1]]=item;
            }
        }
    }
    return ans;
}
};
// @lc code=end

