class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k + 1, 0);  // dp[k] indicates the k-th value in the series
        dp[1] = 1;
        int factor3 = 1, factor5 = 1, factor7 = 1;  // index indicator
        for (int i = 2; i <= k; i++) {
            int num3 = dp[factor3] * 3, num5 = dp[factor5] * 5,
                num7 = dp[factor7] * 7;
            // cout << i << " " << num3 << " " << num5 << " " << num7 << endl;
            // erase duplicated number
            if (num3 <= num5 && num3 <= num7) {
                dp[i] = num3;
                factor3++;
            }
            if (num5 <= num3 && num5 <= num7) {
                dp[i] = num5;
                factor5++;
            }
            if (num7 <= num3 && num7 <= num5) {
                dp[i] = num7;
                factor7++;
            }
        }
        return dp[k];
    }
};