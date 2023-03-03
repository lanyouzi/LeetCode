/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n/2; i++) { // round layer
            for (int j=i; j<n-1-i; j++) {
                // transform 4 corners
                int lt = matrix[i][j];
                int rt = matrix[j][n-1-i];
                int lb = matrix[n-1-j][i];
                int rb = matrix[n-1-i][n-1-j];
                matrix[i][j] = lb;
                matrix[j][n-1-i] = lt;
                matrix[n-1-j][i] = rb;
                matrix[n-1-i][n-1-j] = rt;
            }
        }
    }
};
// @lc code=end

