/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;
        for (auto i = 0; i < 9; i++) {
            bool f[11];
            fill(f, f + 10, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    // cout << i << " " << j << " " << board[i][j] << endl;
                    if (f[board[i][j] - '0'])
                        return false;
                    else
                        f[board[i][j] - '0'] = true;
                }
            }
        }
        for (auto i = 0; i < 9; i++) {
            bool f[11];
            fill(f, f + 10, false);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    // cout << i << " " << j << " " << board[i][j] << endl;
                    if (f[board[j][i] - '0'])
                        return false;
                    else
                        f[board[j][i] - '0'] = true;
                }
            }
        }
        for (auto i = 0; i < 9; i += 3) {
            for (auto j = 0; j < 9; j += 3) {
                bool f[11];
                fill(f, f + 10, false);
                for (auto k = 0; k < 3; k++) {
                    for (auto l = 0; l < 3; l++) {
                        if (board[i + k][j + l] != '.') {
                            if (f[board[i + k][j + l] - '0'])
                                return false;
                            else
                                f[board[i + k][j + l] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
