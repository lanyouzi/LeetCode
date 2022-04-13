/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
   public:
    int getCount(long prefix, long margin) {
        long cur = prefix;
        long next = cur + 1;
        long count = 0;
        while (cur <= margin) {
            count += min(margin - cur + 1, next - cur);
            cur *= 10;
            next *= 10;
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        long p = 1; // location pointer, p==k means get the k-th number
        long prefix = 1;
        while (p < k) {
            long count = getCount(prefix, n);   // get number of child nodes of crrent prefix
            if (p + count > k) {  // k-th number is in the range of prefix
                prefix *= 10;     // let prefix point to the first child node
                p++;
            } else if (p + count <= k) {  // k-th number is NOT in this range
                prefix++;
                p += count;
            }
        }
        return prefix;
    }
};
// @lc code=end
