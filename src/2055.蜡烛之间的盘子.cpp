/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
class Solution {
   public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> ans;
        vector<int> left(n, -1), right(n, -1), canddle_num(n, 0);
        // left[i] means the coordinates of the leftmost candle in the interval
        // [i, n-1] right[i] means the coordinates of the rightmost candle in
        // the interval [0, i] canddle[i] means the number of canddles in the
        // interval [0, i]
        right[0] = s[0] == '|' ? 0 : -1;
        left[n - 1] = s[n - 1] == '|' ? 0 : -1;
        canddle_num[0] = s[0] == '|' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '|') {
                right[i] = i;
                canddle_num[i] = canddle_num[i - 1] + 1;
            } else {
                right[i] = right[i - 1];
                canddle_num[i] = canddle_num[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '|') {
                left[i] = i;
            } else {
                left[i] = left[i + 1];
            }
        }
        for (auto& query : queries) {
            int right_index = right[query[1]], left_index = left[query[0]];

            if (right_index - left_index > 0 && left_index >= 0 &&
                right_index >= 0) {
                // right_index - left_index - 1 means the number of objects in
                // the left and right candle coordinates in the interval, while
                // canddle_num[right_index] - canddle_num[left_index] - 1 means
                // the number of canddles in this case.
                ans.emplace_back(
                    right_index - left_index - 1 -
                    (canddle_num[right_index] - canddle_num[left_index] - 1));
            } else {
                ans.emplace_back(0);
            }
        }
        return ans;
    }
};
// @lc code=end
