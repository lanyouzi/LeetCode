/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX, cur = 0;
        int left = 0, right = 0;
        while (right<blocks.size()) {
            if (blocks[right]=='W') {
                cur++;
            }
            right++;
            if (right-left<k) {
                continue;
            }
            if (right-left>k) {
                if (blocks[left]=='W') {
                    cur--;
                }
                left++;
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

