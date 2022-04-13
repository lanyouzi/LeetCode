/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
   public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int tmp = i;
            bool flag = true;
            while (tmp != 0) {
                int d = tmp % 10;
                if (d == 0 || i % d != 0) {
                    flag = false;
                    break;
                }
                tmp = tmp / 10;
            }
            if (flag)
                ans.emplace_back(i);
        }
        return ans;
    }
};
// @lc code=end
