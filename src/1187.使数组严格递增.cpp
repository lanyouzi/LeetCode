/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-04-20 10:19:57
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-04-20 10:20:05
 * @FilePath: 1187.使数组严格递增.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 */

// @lc code=start
class Solution {
public:
    int maxv = 1e9;
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // 预处理：排序，去重，加哨兵
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        arr1.push_back(maxv); // 右侧哨兵 inf
        arr1.insert(arr1.begin(), -1); // 左侧哨兵 -1
        int n = arr1.size();
        vector<int> dp(n, maxv);
        dp[0] = 0;
        for(int i = 1; i < n; ++i) {
            //1. 如果要替换arr[i]，应当选择arr2中小于arr[i]的最大元素进行替换
            int j = lower_bound(arr2.begin(),arr2.end(), arr1[i]) - arr2.begin();   //  满足arr2[j]>=arr1[i]的最小索引
            for(int k = 1; k <= min(i-1, j); ++k){ // 1. 枚举替换的个数 k = 1 to min(i-1,j)
                // 不断地将arr2[j-k]赋值给arr1[i-k]，直至arr1[i-k-1] < arr2[j-k]
                if(arr1[i-k-1] < arr2[j-k]) {
                    dp[i] = min(dp[i], dp[i-k-1] + k);
                }
            }
            if(arr1[i-1] < arr1[i]) { // 2. 不替换 arr1[i-1]
                dp[i] = min(dp[i], dp[i-1]);
            }
        }

        int res = dp[n-1];
        return (res >= maxv)? -1 : res;
    }
};
// @lc code=end

