/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <bits/stdc++.h>

// O(m+n) 指针后移
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, m = nums1.size(), n = nums2.size(), ans = 0, pre = 0;
        int k = (m + n) / 2;  // point moves k times
        while (k >= 0) {
            if (i >= m || (j < n && nums1[i] >= nums2[j])) {
                pre = ans;
                ans = nums2[j];
                j++;
            } else if (j >= n || (i < m && nums1[i] < nums2[j])) {
                pre = ans;
                ans = nums1[i];
                i++;
            }
            k--;
        }
        cout << pre << " " << ans << endl;
        if ((m + n) & 1 == 1) {
            return ans;
        } else {
            return (pre + ans) * 1.0 / 2;
        }
    }
};
// @lc code=end

// O[log(m+n)] 二分查找
class Solution {
public:
    int findKthNumber(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int k) {
        if (l1>r1) {
            return nums2[l2+k];
        } else if (l2>r2) {
            return nums1[l1+k];
        }else if (k==0) {
            return min(nums1[l1], nums2[l2]);
        }
        int p = (k-1)/2;
        if (l1+p>r1) {
            return findKthNumber(nums1, nums2, l1, r1, l2+p+1, r2, k-p-1);
        } else if (l2+p>r2) {
            return findKthNumber(nums1, nums2, l1+p+1, r1, l2, r2, k-p-1);
        } else if (nums1[l1+p]>=nums2[l2+p]) {
            return findKthNumber(nums1, nums2, l1, r1, l2+p+1, r2, k-p-1);
        } else {
            return findKthNumber(nums1, nums2, l1+p+1, r1, l2, r2, k-p-1);
        }
    }
    // O(log(m+n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int  m = nums1.size()-1, n = nums2.size()-1;
        int k = (m+n+1)/2;
        if ((m + n) & 1 == 1) {
            return findKthNumber(nums1, nums2, 0, m, 0, n, k);
        } else {
            int p = findKthNumber(nums1, nums2, 0, m, 0, n, k), q = findKthNumber(nums1, nums2, 0, m, 0, n, k + 1);
            return (p+q)*1.0/2;
        }
    }
};