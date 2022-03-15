/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
class Solution {
public:
    long long max_score = 0;
    int cnt = 0;
    int n;
    vector<vector<int>> children;

    int dfs(int node) {
        long long score = 1;
        int size = n - 1;
        for (int child : children[node]) {
            int t = dfs(child);
            score *= t;
            size -= t;
        }
        if (node != 0) {
            score *= size;
        }
        if (score == max_score) {
            cnt++;
        } else if (score > max_score) {
            max_score = score;
            cnt = 1;
        }
        return n - size;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            int p = parents[i];
            if (p != -1) {
                children[p].emplace_back(i);
            }
        }
        dfs(0);
        return cnt;
    }
};
// @lc code=end

