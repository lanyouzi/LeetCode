/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
   public:
    void certainDiagonalOrder(vector<vector<int>>& mat,
                              vector<int>& v,
                              int layer,
                              bool reverse) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0, j = layer; i < layer, j >= 0; i++, j--) {
            if (reverse == false) {
                if (i < n && j < m) {
                    v.emplace_back(mat[i][j]);
                }
            } else {
                if (j < n && i < m) {
                    v.emplace_back(mat[j][i]);
                }
            }
        }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        for (int i=0; i<2*max(n, m); i++) {
            certainDiagonalOrder(mat, ans, i, i%2==0);
        }
        return ans;
    }
};
// @lc code=end
