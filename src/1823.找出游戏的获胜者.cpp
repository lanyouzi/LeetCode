/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
   public:
    int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        return (k - 1 + findTheWinner(n - 1, k)) % n + 1;
    }
    // int findTheWinner(int n, int k) {
    //     int rest = n;
    //     vector<bool> flag(n, true);
    //     int pos = -1, cycle = 0;
    //     while (rest > 1) {
    //         pos = (pos + 1) % n;
    //         if (flag[pos]) {
    //             cycle++;
    //             if (cycle == k) {
    //                 rest--;
    //                 flag[pos] = false;
    //                 cycle = 0;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < n; i++) {
    //         if (flag[i]) {
    //             return i + 1;
    //         }
    //     }
    //     return 0;
    // }
};
// @lc code=end
