/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

// @lc code=start
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, int> informs;
        vector<vector<int>> adj(n);
        for (int i=0; i<n; i++) {
            if (manager[i]!=-1)
                adj[manager[i]].emplace_back(i);
        }
        function<int(int cur)> dfs = [&](int cur) {
            if(informs.count(cur))
                return informs[cur];
            int max_time = 0;
            for (int i=0; i<adj[cur].size(); i++) {
                max_time = max(max_time, dfs(adj[cur][i]));
            }
            informs[cur] = informTime[cur] + max_time;
            return informs[cur];
        };
        return dfs(headID);
    }
};
// @lc code=end

