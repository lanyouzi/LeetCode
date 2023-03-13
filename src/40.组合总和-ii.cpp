/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& candidates, int target, int i) {
        if (target==0) {
            ans.emplace_back(path);
            return;
        }
        for (int j=i; j<candidates.size() && target-candidates[j]>=0; j++) {
            if (j>i && candidates[j]==candidates[j-1]) {    // 同一层去重
                continue;
            }
            path.emplace_back(candidates[j]);
            dfs(candidates, target - candidates[j], j+1);
            path.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

