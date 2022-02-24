/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution {
   public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> vertical_max_index, horizontal_max_index;
        for (int i = 0; i < grid.size(); i++) {
            int max_ = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > grid[i][max_]) {
                    max_ = j;
                }
            }
            horizontal_max_index.emplace_back(max_);
        }
        for (int i = 0; i < grid[0].size(); i++) {
            int max_ = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] > grid[max_][i]) {
                    max_ = j;
                }
            }
            vertical_max_index.emplace_back(max_);
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int res = min(grid[i][horizontal_max_index[i]],
                              grid[vertical_max_index[j]][j]);
                ans += (res - grid[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end
