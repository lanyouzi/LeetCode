/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> offset(n, 0);  // offset[i]表示[0,i-1]中有多少个零
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] == 0) {
                offset[i] = offset[i - 1] + 1;
            } else {
                offset[i] = offset[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i + offset[i] < n) {
                arr[i + offset[i]] = arr[i];
            }
            // 偏移位不为零，说明该索引下值要右移，非初始值，因此统一设为零即可
            if (offset[i] > 0) {
                arr[i] = 0;
            }
        }
    }
};
// @lc code=end
