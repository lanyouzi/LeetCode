/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        // i：最右的非最小数字索引
        // j：在j右边的小于arr[j]的最大数的索引
        int n = arr.size(), l=n-1, r;
        for (int i=n-2; i>=0; i--) {
            if (arr[i]>arr[i+1]) {
                l = i;
                break;
            }
        }
        if (l==n-1) {
            return arr;
        }
        r = l+1;
        for (int i=l+1; i<n; i++) {
            if (arr[i]>arr[r] && arr[i]<arr[l]) {
                r = i;
            }
        }
        swap(arr[l], arr[r]);
        return arr;

    }
};
// @lc code=end

