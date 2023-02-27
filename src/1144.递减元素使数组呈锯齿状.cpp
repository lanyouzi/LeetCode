/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int count1 = 0, count2 = 0; // down-up, and up-down
        int target1, target2, thresh;
        int n = nums.size();
        if (n==1)
            return 0;
        for (int i=0; i<n; i++) {
            thresh = min(i>0?nums[i-1]:INT_MAX, i<n-1?nums[i+1]:INT_MAX) - 1;
            if ((i&1)==1) {     // down-up
                count1+=max(nums[i]-thresh, 0);
            } else {            //  up-down  
                count2+=max(nums[i]-thresh, 0);
            }
        }
        return min(count1, count2);
    }
};
// @lc code=end

