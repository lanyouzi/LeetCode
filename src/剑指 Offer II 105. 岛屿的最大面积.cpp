/*
 * @Author: mrk-lyz mrk_lanyouzi@yeah.net
 * @Date: 2022-07-16 10:19:09
 * @LastEditTime: 2022-07-16 10:21:05
 * @FilePath: /LeetCode/src/剑指 Offer II 105. 岛屿的最大面积.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by mrk-lyz mrk_lanyouzi@yeah.net, All Rights Reserved. 
 */
class Solution {
public:
    int ans;
    int row, col;
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int top = 0, bottom = 0, left = 0, right = 0;
        if (i>0 && grid[i-1][j] && !visited[i-1][j]) {
            top = dfs(grid, visited, i-1, j);
        }
        if (i<row-1 && grid[i+1][j] && !visited[i+1][j]) {
            bottom = dfs(grid, visited, i+1, j);
        }
        if (j>0 && grid[i][j-1] && !visited[i][j-1]) {
            left = dfs(grid, visited, i, j-1);
        }
        if (j<col-1 && grid[i][j+1] && !visited[i][j+1]) {
            right = dfs(grid, visited, i, j+1);
        }
        return 1+left+right+bottom+top;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans = 0;
        row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    int cur = dfs(grid, visited, i, j);
                    ans = max(cur, ans);
                }
            }
        }
        return ans;
    }
};