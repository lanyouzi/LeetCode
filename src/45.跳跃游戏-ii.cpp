/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        map<int, int> available_index;   // <index, rest_step>
        available_index[0] = nums[0];
        for (int i=1; i<n; i++) {
            int min_step = INT_MAX;
            for (auto it:available_index) {
                // cout << it.first << " " << it.second << endl;
                min_step = min(min_step, dp[it.first]+1);
            }
            // cout << endl;
            dp[i] = min_step;
            for (auto it=available_index.begin(); it!=available_index.end();) {
                it->second--;
                if (it->second<= 0) {
                    available_index.erase(it++);
                } else { 
                    it++;
                }
            }
            available_index.insert(make_pair(i, nums[i]));
        }
        return dp[n-1];
    }
};
// @lc code=end

