/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */

// @lc code=start
class Solution {
public:
void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, int color){
    visited[row][col] = 1;
    if (row>=1 && !visited[row-1][col] && grid[row-1][col]==color) {
        dfs(grid, visited, row-1, col, color);
    }
    if (row<grid.size()-1 && !visited[row+1][col] && grid[row+1][col]==color) {
        dfs(grid, visited, row+1, col, color);
    }
    if (col>=1 && !visited[row][col-1] && grid[row][col-1]==color) {
        dfs(grid, visited, row, col-1, color);
    }
    if (col<grid[0].size()-1 && !visited[row][col+1] && grid[row][col+1]==color) {
        dfs(grid, visited, row, col+1, color);
    }
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                int row,
                                int col,
                                int color) {
    vector<vector<int>> visited(grid.size());
    for (auto &temp:visited) {
        temp.resize(grid[0].size());
        fill(temp.begin(), temp.end(), 0);
    }
    dfs(grid, visited, row, col, grid[row][col]);
    for (int i=0; i<grid.size(); i++){
        for (int j=0; j<grid[0].size(); j++){
            if (visited[i][j]==1){
                if (i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1) {
                    grid[i][j]=color;
                }
                else if(visited[i-1][j]==0 || visited[i+1][j]==0 || visited[i][j-1]==0 || visited[i][j+1]==0 ) {
                    grid[i][j]=color;
                }  
            }
        }
    }
    return grid;
}
};
// @lc code=end

