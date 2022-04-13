/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
bool cmp(int a, int b) {
    return abs(a) < abs(b);
}
class Solution {
   public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (auto& item : arr) {
            mp[item] += 1;
        }
        if (mp[0] % 2 != 0) {  // number of 0 must be divisible by 2
            return false;
        }
        vector<int> vals;
        for (auto& k : mp) {
            vals.emplace_back(k.first);
        }
        sort(vals.begin(), vals.end(), cmp);
        for (auto& item : vals) {
            if (mp[2 * item] < mp[item]) {
                return false;
            }
            mp[2 * item] -= mp[item];
        }
        return true;
    }
};
// @lc code=end
