/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
bool static cmp(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), cmp);
    priority_queue<int> q;
    int deadline = 0;
    for (auto& item : courses) {
        // cout << item[0] << " " << item[1] << endl;
        if (deadline+item[0]<=item[1]) {
            deadline = deadline+item[0];
            q.push(item[0]);
        } else if (!q.empty() && q.top()>item[0]) {
            deadline = deadline - q.top()+item[0];
            q.pop();
            q.push(item[0]);
        }
    }
    return q.size();
}
};
// @lc code=end
