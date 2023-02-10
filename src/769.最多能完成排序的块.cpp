/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int max_value = 0, ans = 0;
        for (int i=0; i<n; i++) {
            max_value = max(max_value, arr[i]);
            if (max_value==i) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

