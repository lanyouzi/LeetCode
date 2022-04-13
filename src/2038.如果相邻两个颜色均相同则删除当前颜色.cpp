/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

// @lc code=start
class Solution {
   public:
    bool winnerOfGame(string colors) {
        int flag_a = 0, flag_b = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1] &&
                colors[i] == 'A') {
                flag_a++;
            }
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1] &&
                colors[i] == 'B') {
                flag_b++;
            }
        }
        return flag_a > flag_b;
    }
};
// @lc code=end
