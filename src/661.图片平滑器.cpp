/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> offset = {{-1, -1}, {0, -1}, {1, -1},
                                      {-1, 0},  {0, 0},  {1, 0},
                                      {-1, 1},  {0, 1},  {1, 1}};
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int value = 0;
                int count = 0;
                for (auto& item : offset) {
                    int di = i + item[0], dj = j + item[1];
                    if (di >= 0 && di < m && dj >= 0 && dj < n) {
                        value += img[di][dj];
                        count += 1;
                    }
                }
                ans[i][j] = value / count;
            }
        }
        return ans;
    }
};
// @lc code=end
