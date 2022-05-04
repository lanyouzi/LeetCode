/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution {
   public:
    int binaryGap(int n) {
        int ans = 0;
        int prefix = -1;
        bitset<32> bs(n);
        for (int i = 0; i < bs.size(); i++) {
            if (bs[i] == 1) {
                if (prefix >= 0) {
                    ans = max(ans, i - prefix);
                }
                prefix = i;
            }
        }
        return ans;
    }
};
// @lc code=end
