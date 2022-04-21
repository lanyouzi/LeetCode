/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution {
   public:
    void dfs(vector<int>& ans, int k, int n) {
        if (k > n) {
            return;
        }
        if (!k == 0)
            ans.emplace_back(k);
        for (int i = 0; i < 10; i++) {
            if (!(k == 0 && i == 0)) {
                dfs(ans, 10 * k + i, n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        dfs(ans, 0, n);
        return ans;
    }
};
// @lc code=end
