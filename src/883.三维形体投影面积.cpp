/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
   public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        vector<int> x(50, 0), y(50, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    ans++;
                    x[i] = max(x[i], grid[i][j]);
                    y[j] = max(y[j], grid[i][j]);
                }
            }
        }
        for (auto& item : x) {
            ans += item;
        }
        for (auto& item : y) {
            ans += item;
        }
        return ans;
    }
};
// @lc code=end
