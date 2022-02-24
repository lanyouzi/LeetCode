/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
   public:
    void EndGame(char a, char b, char c, int& num1, int& num2) {
        if (a == 'X' && a == b && b == c) {
            num1++;
        } else if (a == 'O' && a == b && b == c) {
            num2++;
        }
    }
    bool validTicTacToe(vector<string>& board) {
        int num_x = 0, num_o = 0;
        bool win1 = false, win2 = false;
        for (auto& str : board) {
            for (auto& ch : str) {
                if (ch == 'X') {
                    num_x++;
                }
                if (ch == 'O') {
                    num_o++;
                }
            }
        }
        int triple_line1 = 0, triple_line2 = 0;
        for (auto& str : board) {
            EndGame(str[0], str[1], str[2], triple_line1, triple_line2);
        }
        if (triple_line1 + triple_line2 > 1) {
            return false;
        }
        if (triple_line1 > 0)
            win1 = true;
        if (triple_line2 > 0)
            win2 = true;
        triple_line1 = 0, triple_line2 = 0;
        for (int i = 0; i < 3; i++) {
            EndGame(board[0][i], board[1][i], board[2][i], triple_line1,
                    triple_line2);
        }
        if (triple_line1 + triple_line2 > 1) {
            return false;
        }
        if (triple_line1 > 0)
            win1 = true;
        if (triple_line2 > 0)
            win2 = true;
        EndGame(board[0][0], board[1][1], board[2][2], triple_line1,
                triple_line2);
        EndGame(board[2][0], board[1][1], board[0][2], triple_line1,
                triple_line2);
        if (triple_line1 > 0)
            win1 = true;
        if (triple_line2 > 0)
            win2 = true;
        if ((!win1 && num_x == num_o) || (!win2 && num_x == num_o + 1)) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end
