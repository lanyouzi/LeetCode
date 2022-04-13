/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
   public:
    // double pointers, always move the pointer which indicates the lower height.
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left != right) {
            int area = min(height[right], height[left]) * (right - left);
            if (ans < area) {
                ans = area;
            }
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end
