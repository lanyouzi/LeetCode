/*
 * @lc app=leetcode.cn id=1223 lang=cpp
 *
 * [1223] 掷骰子模拟
 */

// @lc code=start
class Solution {
public:
    static const int MOD=1e9+7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector dp(n+1, vector<vector<int>>(6, vector<int>(16, 0)));
        // 定义状态d[i][j][k]表示已经完成了i次掷骰子，第i次掷的是j，并且已经连续掷了k次j的合法序列数。
        for (int i=0; i<6; i++) {
            dp[1][i][1] = 1;
        }
        for (int i=2; i<=n; i++) {                      // 已完成i次
            for (int j=0; j<6; j++) {                   // 第i次投出j
                for (int k=2; k<=rollMax[j]+1; k++) {   // j已经连续k次，需计算k<=rollmax[j]+1的部分
                    for (int p=0; p<6; p++) {           // 当前投出点数为p
                        if (p!=j) {                     // 新投出的点数与原末尾点数不同
                            dp[i][p][1] = (dp[i][p][1] + dp[i-1][j][k-1]) % MOD;    //由于此时需要用到dp[i-1][j][k-1]的数据，k必须遍历到rollMax[j]+1的值
                        } else if (k<=rollMax[j]) {   // p==j
                            dp[i][p][k] = (dp[i][p][k] + dp[i-1][j][k-1]) % MOD;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int j=0; j<6; j++) {
            for (int k=1; k<=rollMax[j]; k++) {
                ans = (ans + dp[n][j][k]) % MOD;
            }
        }
        return ans;
    }
};
// @lc code=end

