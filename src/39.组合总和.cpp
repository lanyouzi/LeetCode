/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2022-09-23 18:48:21
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-11 14:41:23
 * @FilePath: 39.组合总和.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<int>& path, int index, vector<vector<int>>& ans) {
        if (index>=candidates.size()) {
            return;
        }
        if (target==0) {
            ans.emplace_back(path);
            return;
        }
        // select index-th number
        if (target-candidates[index]>=0){
            path.emplace_back(candidates[index]);
            dfs(candidates, target-candidates[index], path, index, ans);
            path.pop_back();
        }
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

