/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
class Solution {
public:
    struct Class{
        int pass;
        int total;
        Class(int p, int t):pass(p),total(t) {}
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [&](const Class &a, const Class &b) {
            return (long long) b.total*(b.total+1)*(a.total-a.pass)< (long long) a.total*(a.total+1)*(b.total-b.pass);
        };
        priority_queue<Class, vector<Class>, decltype(cmp)> q(cmp);
        for (auto& c:classes) {
            q.push({c[0], c[1]});
        }
        for (int i=0; i<extraStudents; i++) {
            Class cur = q.top();
            q.pop();
            q.push({cur.pass+1, cur.total+1});
        }
        double ans = 0;
        for (int i = 0; i < classes.size(); i++) {
            Class cur = q.top();
            q.pop();
            ans += 1.0 * cur.pass / cur.total;
        }
        return ans / classes.size();
    }
};
// @lc code=end

