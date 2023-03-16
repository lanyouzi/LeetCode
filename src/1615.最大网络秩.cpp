/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0, cur;
        vector<vector<int>> adj(n);
        map<int, int> exists;
        for (auto road:roads) {
            adj[road[0]].emplace_back(road[1]);
            adj[road[1]].emplace_back(road[0]);
            exists[101*min(road[0], road[1])+max(road[0], road[1])] = 1;
        }
        for (int i=0; i<n; i++) {
            for ( int j=0; j<n; j++) {
                if (i!=j) {
                    cur = adj[i].size()+adj[j].size()-exists[101*min(i, j)+max(i, j)];
                    ans = max(cur, ans);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

