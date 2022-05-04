/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
   public:
    vector<vector<bool>> P, A;
    vector<vector<int>> ans;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        P = vector<vector<bool>>(m, vector<bool>(n, false));
        A = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            dfs(heights, P, i, 0);
            dfs(heights, A, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, P, 0, i);
            dfs(heights, A, m - 1, i);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int i,
             int j) {
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        if (P[i][j] && A[i][j]) {
            vector<int> dot = {i, j};
            ans.emplace_back(dot);
        }
        if (i > 0 && heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, visited, i - 1, j);
        }
        if (j > 0 && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, visited, i, j - 1);
        }
        if (i < heights.size() - 1 && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, visited, i + 1, j);
        }
        if (j < heights[0].size() - 1 && heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, visited, i, j + 1);
        }
    }
};
// @lc code=end
