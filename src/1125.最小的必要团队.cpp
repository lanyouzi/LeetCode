/*
 * @lc app=leetcode.cn id=1125 lang=cpp
 *
 * [1125] 最小的必要团队
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // DP+状态压缩，状态n的第i位为1，表示需要第i个技能
        int n = req_skills.size(), m = people.size();
        vector<vector<int>> dp(1<<n);   // 
        unordered_map<string, int> mp;
        for (int i=0; i<n; i++) {
            mp[req_skills[i]] = i;
        }
        for (int i=0; i<m; i++) {
            int cur = 0;
            for (string& s : people[i]) {
                cur |= 1 << mp[s];
            }
            for (int prev=0; prev<dp.size(); prev++) {
                // 判断当前prev是否合法，只有prev=0时dp[prev]才可能为空
                if (prev>0 && dp[prev].empty()) {
                    continue;
                }
                // 计算加入person[i]后的技能池
                int comp = prev | cur;
                if (comp == prev) { // 如果技能池无变化，直接进入下一轮遍历
                    continue;
                }
                if (dp[comp].empty() || dp[comp].size()>dp[prev].size()+1) {
                    // dp[comp]为空：没有出现过这种状态
                    // dp[comp].size()>dp[prev].size()+1：具有更优解
                    dp[comp] = dp[prev];
                    dp[comp].push_back(i);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
// @lc code=end

