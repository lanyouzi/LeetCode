/*
 * @lc app=leetcode.cn id=1040 lang=cpp
 *
 * [1040] 移动石子直到连续 II
 */

// @lc code=start
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        // 将stones从小到大排序
        // 最大移动次数为s[0]~s[n-2]或s[1]~s[n-1]之间空位数量的最大值
        // 最小移动次数为n-长度为n的窗口中的最大石子数量
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int e1 = stones[n-2]-stones[0]-n+2, e2 = stones[n-1]-stones[1]-n+2;
        int max_num = max(e1, e2), min_num = 0;
        if (e1 == 0 || e2 == 0) // 任一子区间无空，只需移动两次，但不大于max_num
            return {min(2,max_num), max_num};

        int left = 0, right = 0, max_cnt = 0, cur_len = 0;
        while (right<n) {
            cur_len = stones[right++]-stones[left];    // end-point sensitive
            while (cur_len+1>n) {
                cur_len = cur_len + stones[left] - stones[left+1];
                left++;
            }
            max_cnt = max(max_cnt, right-left);
        }
        return {n-max_cnt, max_num};
    }
};
// @lc code=end

