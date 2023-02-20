/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
public:
    // 双指针滑动窗口
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        int prod = 1, i = 0;
        for (int j = 0; j < n; j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            ret += j - i + 1;   // 此时以下标j为尾元素的序列有j-i+1个
        }
        return ret;
    }
};

/*
    // 自力更生：滑动窗口
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i = 0, j = 0;
        int sum = 1;
        while (i < n) {     // 遍历起始位置
            while (j < n && sum * nums[j] < k) {    // 尽可能扩充序列长度
                sum *= nums[j];
                j++;
            }
            if (j > i) {    // 当前满足条件的序列不为空，可以删头加尾
                sum /= nums[i];
                ans += j - i;
            } else {        // 当前满足条件的序列为空，应当从下一个数开始计算
                j = i + 1;
            }
            i++;
        }
        return ans;
    }

 */
// @lc code=end
