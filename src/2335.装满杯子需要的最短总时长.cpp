/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans=0;
        auto cmp = [](const int a, const int b){return a<b;};
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        q.push(amount[0]);
        q.push(amount[1]);
        q.push(amount[2]);
        while (!q.empty()) {
            if (q.size()==1 || q.top()==0) {
                ans+=q.top();
                q.pop();
            } else {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                if (a-1>0)
                    q.push(a-1);
                if (b-1>0)
                    q.push(b-1);
                ans+=1;
            }
        }
        return ans;
    }
};
// @lc code=end

