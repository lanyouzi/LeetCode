/*
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */

// @lc code=start
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    } else {
        return a[1] < b[1];
    }
}
int cross_product(const vector<int>& p,
                  const vector<int>& q,
                  const vector<int>& r) {
    return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]);
}
class Solution {
   public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 3) {
            return trees;
        }
        sort(trees.begin(), trees.end(),
             cmp);  // 按照x第一关键字升序，y第二关键字降序排序
        vector<vector<int>> ans;
        vector<int> st;
        vector<int> visited(n, false);
        st.emplace_back(0);
        for (int i = 1; i < n; i++) {  // 找下凸边
            while (st.size() > 1 &&
                   cross_product(trees[st[st.size() - 2]], trees[st.back()],
                                 trees[i]) < 0) {
                visited[st.back()] = false;
                st.pop_back();
            }
            visited[i] = true;
            st.emplace_back(i);
        }
        int m = st.size();
        for (int i = n - 2; i >= 0; i--) {  // 找上凸边
            if (!visited[i]) {
                while (st.size() > m &&
                       cross_product(trees[st[st.size() - 2]], trees[st.back()],
                                     trees[i]) < 0) {
                    st.pop_back();
                }
                st.emplace_back(i);
            }
        }
        st.pop_back();
        for (auto& node : st) {
            ans.emplace_back(trees[node]);
        }
        return ans;
    }
};
// @lc code=end
