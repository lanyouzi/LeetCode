/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    // Double pointers
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end()); // order by starts
        sort(endIntervals.begin(), endIntervals.end());     // order by ends
        vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++) {
            while (j < n && endIntervals[i].first > startIntervals[j].first) {
                j++;
            }
            if (j < n) {
                ans[endIntervals[i].second] = startIntervals[j].second;
            }
        }
        return ans;
    }
};
// @lc code=end

