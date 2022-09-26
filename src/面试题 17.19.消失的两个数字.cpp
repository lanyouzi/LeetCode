/* 
给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？
 */
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int xorsum = 0;     // x1 xor x2 = xorsum
        int n = nums.size() + 2;
        for (int num : nums) {
            xorsum ^= num;
        }
        for (int i = 1; i <= n; i++) {
            xorsum ^= i;
        }
        // use x&(-x) to find the lowest non-zero bit (assume to be l-th bit)
        // then difine two categories: l-th bit is 0 or not.
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;   // x1 and x2 will be dispersed into different categories
        for (int num : nums) {
            if (num & lsb) {
                type1 ^= num;
            } else {
                type2 ^= num;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i & lsb) {
                type1 ^= i;
            } else {
                type2 ^= i;
            }
        }
        return {type1, type2};
    }
};