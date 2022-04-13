/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
   public:
    bool hasAlternatingBits(int n) {
        int count = 0;
        bool pre;
        while (n != 0) {
            bool flag = n - ((n >> 1) << 1);
            n = (n >> 1);
            if (count > 0) {
                if (!(flag ^ pre)) {
                    return false;
                }
            }
            count++;
            pre = flag;
        }
        return true;
    }
};
// @lc code=end
