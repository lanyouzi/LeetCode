/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = 0, ans = n, prefix_sum = 0, rest;
        unordered_map<int, int> mp;     // <target, max_index>
        for (int i=0; i<n; i++) {
            target = (target + nums[i])%p;
        }
        if (!target) {
            return 0;
        }
        mp[0] = -1; // 必须记录前缀和0的索引
        // 转化为前缀和，原问题等价于求端点差为target的最小区间长度
        for (int i=0; i<n; i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            rest = (prefix_sum - target + p) % p;
            mp[prefix_sum] = i;
            ans = min(ans, mp.count(rest)?i-mp[rest]:INT_MAX);  // 减去(i-mp[rest], i]这部分
        }
        return ans==n?-1:ans;
        
    }
};
// @lc code=end

