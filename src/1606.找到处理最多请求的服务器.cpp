/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */

// @lc code=start
class Solution {
   public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> servers(k, 0);
        vector<int> works(k, 0);
        set<int> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;     // <finish_time, index>
        vector<int> ans;
        int max_work = 0;
        int time = 0;
        for (int i=0; i<k; i++) {
            available.insert(i);
        }
        for (int i = 0; i < arrival.size(); i++) {
            time = arrival[i];
            while (!busy.empty() && busy.top().first<=time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if(available.empty()) {
                continue;
            }
            auto it = available.lower_bound(i%k);
            if (it == available.end()) {
                it = available.begin();
            }
            int index  = *it;
            busy.push({time+load[i], index});
            available.erase(index);
            works[index] += 1;
            if (works[index] == max_work) {
                ans.emplace_back(index);
            } else if (works[index] > max_work) {
                ans.clear();
                max_work = works[index];
                ans.emplace_back(index);
            }
        }
        return ans;
    }
};
// @lc code=end
