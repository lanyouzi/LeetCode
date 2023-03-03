/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==INT_MIN && divisor==-1) {
            return INT_MAX;
        }
        if (dividend==INT_MIN && divisor==1) {
            return INT_MIN;
        }
        bool is_neg = (dividend<0)^(divisor<0);
        int ans = 0;
        // 因为有INT_MAX的存在，需要转为负数处——倍增法
        dividend = -abs(dividend);
        divisor = -abs(divisor);
        while (dividend<=divisor) {
            int tmp = divisor, count = 1;
            while (dividend-tmp<=tmp) {
                tmp+=tmp;
                count+=count;
            }
            dividend-=tmp;
            ans+=count;
        }
        return is_neg?-ans:ans;
        
    }
};
// @lc code=end

