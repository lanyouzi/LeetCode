/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
/* 
从度为1的点开始BFS
 */
class Solution {
   public:
    vector<int> flag;
    vector<vector<int>> nexts;
    int getHeight(int r) {
        flag[r] = true;
        int maxHeight = 0;
        for (auto& item : nexts[r]) {
            if (!flag[item]) {
                int h = getHeight(item);
                if (h > maxHeight) {
                    maxHeight = h;
                }
            }
        }
        return maxHeight + 1;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1) {
            ans.emplace_back(0);
            return ans;
        }
        vector<int> degree(n, 0);   // degrees of each node
        vector<vector<int>> mp(n);  // adjacency list
        for (auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            mp[edge[0]].emplace_back(edge[1]);
            mp[edge[1]].emplace_back(edge[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            ans.clear();
            int cn = q.size();
            while (cn--) {
                int current = q.front();
                ans.emplace_back(current);
                q.pop();
                for (auto& next : mp[current]) {
                    degree[next]--;
                    if (degree[next] == 1) {
                        q.push(next);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
