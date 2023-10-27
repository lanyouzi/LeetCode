/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] 填充书架
 */

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, 1e6+10);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            int cur_width = 0, max_height = 0;
            for (int j=i; j>=1; j--) {
                cur_width = cur_width + books[j-1][0];
                if (cur_width>shelfWidth) {
                    break;
                }
                max_height = max(max_height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + max_height);
            }
        }

        return dp[n];
    }
};
// @lc code=end

