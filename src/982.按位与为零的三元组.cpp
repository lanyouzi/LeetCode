/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int> &nums) {
        int cnt[1 << 16]{};
        for (int x : nums)  // 先枚举x&y，再找对应的z
            for (int y : nums)
                ++cnt[x & y];
        int ans = 0;
        for (int m : nums) {
            m ^= 0xffff;
            int s = m;
            do { // 枚举 m 的子集（包括空集）
                ans += cnt[s];
                s = (s - 1) & m;
            } while (s != m);
        }
        return ans;
    }
};
// @lc code=end

