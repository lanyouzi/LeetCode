/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // 小 = 大
        // 左小 + 右小 = 左大 + 右大
        // 左小 - 左大 = 右大 - 右小
        //  1   + (-1) =  1   + (-1)
        // 可以用map记录差分值出现的次数
        // 从目标索引向两边发散，对于奇数长度的子串，找到差值相等的点对数量
        // 对于偶数长度的子串，找到左边差值=右边差值-1
        int pos = find(nums.begin(), nums.end(), k) - nums.begin();
        int x = 0;
        unordered_map<int, int> cnt = {{0, 1}}; // 差分为0表示目标索引
        for (int i=pos-1; i>=0; i--) {
            x+=nums[i]<k?1:-1;
            cnt[x]++;
        }
        int ans = cnt[0]+cnt[-1];
        x = 0;
        for (int i=pos+1; i<nums.size(); i++) {
            x+=nums[i]>k?1:-1;
            ans+=(cnt[x]+cnt[x-1]);
        }
        return ans;
    }
};
// @lc code=end

