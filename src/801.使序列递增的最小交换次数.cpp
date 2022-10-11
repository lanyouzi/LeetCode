/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size();
        // dp[i][0] indicates min swap steps of dp[0]~dp[i] when NOT swap i-th item,
        // while dp[i][1] does.
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            bool flag1 = nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1];
            bool flag2 = nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1];
            if (flag1 && !flag2) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            } else if (!flag1 && flag2) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + 1;

            } else {  // flag1 && flag2
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
    // scrowing array version
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size();
        // dp[i][0] indicates min swap steps of dp[0]~dp[i] when NOT swap i-th item,
        // while dp[i][1] does.
        int cnt1 = 0, cnt2 = 1;
        for (int i = 1; i < n; i++) {
            bool flag1 = nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1];
            bool flag2 = nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1];
            int tmp;
            if (flag1 && !flag2) {
                cnt1 = cnt1;
                cnt2 = cnt2 + 1;
            } else if (!flag1 && flag2) {
                tmp = cnt1;
                cnt1 = cnt2;
                cnt2 = tmp + 1;
            } else {  // flag1 && flag2
                cnt1 = min(cnt1, cnt2);
                cnt2 = cnt1 + 1;
            }
        }
        return min(cnt1, cnt2);
    }
};
// @lc code=end

