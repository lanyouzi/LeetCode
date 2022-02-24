/*
 * @lc app=leetcode.cn id=1705 lang=cpp
 *
 * [1705] 吃苹果的最大数目
 */

// @lc code=start
class Solution {
public:
int eatenApples(vector<int>& apples, vector<int>& days) {
    int ans = 0;
    int day = 0;
    int n = apples.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    while (day < n || !q.empty()) {
        if (day < n && apples[day] > 0) {
            pair<int, int> pr = {day + days[day] - 1, apples[day]};
            q.push(pr);
        }
        // 若最早过期的苹果已经过期，或者没有苹果了，就将其删除
        while (!q.empty() && q.top().first < day) {
            q.pop();
        }
        if (!q.empty()) {   // 尚有苹果未食用
            pair<int, int> pr = q.top();
            q.pop();
            if (pr.second > 1 && pr.first >= day) {
                pr.second--;
                q.push(pr); 
            }
            ans++;
        }
        day++;
    }
    return ans;
}
};
// @lc code=end

