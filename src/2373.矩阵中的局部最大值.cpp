/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        auto get_max_value = [&](int p, int q) {
            int max_value = INT_MIN;
            for (int i=-1; i<=1; i++) {
                for (int j=-1; j<=1; j++) {
                    max_value = max(max_value, grid[p+i][q+j]);
                }
            }
            return max_value;
        };
        for (int i=1; i<n-1; i++) {
            for (int j=1; j<n-1; j++) {
                ans[i-1][j-1] = get_max_value(i, j);
            }
        }
        return ans;
    }
};
// @lc code=end

