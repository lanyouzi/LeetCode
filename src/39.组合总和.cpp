/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    // backtracking
    void dfs(vector<int>& candidates, int target, vector<int>& path, int index, vector<vector<int>>& ans) {
        if (target<0 || index>=candidates.size()) {
            return;
        }
        if (target==0) {
            ans.emplace_back(path);
            return;
        }
        // select index-th number
        path.emplace_back(candidates[index]);
        dfs(candidates, target-candidates[index], path, index, ans);
        path.pop_back();
        // ignore index-th number
        dfs(candidates, target, path, index+1, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(candidates, target, path, 0, ans);
        return ans;
    }
};
// @lc code=end

