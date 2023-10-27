/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-05-05 09:57:33
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-05-06 11:36:31
 * @FilePath: 2432.处理用时最长的那个任务的员工.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-05-05 09:57:33
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-05-05 09:57:39
 * @FilePath: 2432.处理用时最长的那个任务的员工.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=2432 lang=cpp
 *
 * [2432] 处理用时最长的那个任务的员工
 */

// @lc code=start
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max_time = 0, ans, pre = 0;
        for (int i=0; i<logs.size(); i++) {
            if (logs[i][1]-pre>max_time) {
                max_time = logs[i][1]-pre;
                ans = logs[i][0];
            } else if (logs[i][1]-pre==max_time) {
                ans = min(ans, logs[i][0]);
            }
            pre = logs[i][1];
        }
        return ans;
    }
};
// @lc code=end

