/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
   public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx(n), ans(n);
        iota(idx.begin(), idx.end(), 0);  // auto-increment assignment
        // sort the index (k-th value of nums2 locates in idx[k])
        sort(idx.begin(), idx.end(),
             [&](int i, int j) { return nums2[i] < nums2[j]; });
        sort(nums1.begin(), nums1.end());
        int left = 0, right = n - 1;
        for (auto item : nums1) {
            cout << item << " " << nums2[idx[left]] << endl;
            if (item > nums2[idx[left]]) {
                ans[idx[left++]] = item;
            } else {
                ans[idx[right--]] = item;
            }
        }
        return ans;
    }
};
// @lc code=end
