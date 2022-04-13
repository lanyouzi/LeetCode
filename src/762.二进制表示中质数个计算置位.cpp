/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
   public:
    unordered_map<int, bool> mp;
    bool isprime(int n) {
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                mp[n] = false;
                return false;
            }
        }
        mp[n] = true;
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        mp[0] = false;
        mp[1] = false;
        mp[2] = true;
        for (int i = left; i <= right; i++) {
            bitset<24> bs(i);
            if (isprime(bs.count())) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
