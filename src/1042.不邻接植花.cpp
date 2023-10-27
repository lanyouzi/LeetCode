/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution {
public:
    // nlogn解法
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> flag(n, 0);
        vector<int> ans(n, -1);
        for (auto&path:paths) {
            if (path[0]>path[1]) {
                swap(path[0], path[1]);
            }
            path[0]--;
            path[1]--;
        }
        sort(paths.begin(), paths.end(), [](vector<int> &p1, vector<int> &p2) {
            return p1[0]<p2[0];
        });
        for (auto& path:paths) {
            int from = path[0], to = path[1];
            if (ans[from]==-1) {
                int i;
                for (i=0; i<4; i++) {
                    if ((flag[from]&(1<<i))==0) {
                        ans[from] = i;
                        break;
                    }
                }
            }
            flag[to] = (flag[to]|(1<<ans[from]));

        }
        for (int i=0; i<n; i++) {
            if (ans[i]==-1)  {
                for(int j=0; j<4; j++) {
                    if ((flag[i]&(1<<j))==0) {
                        ans[i] = j;
                        break;
                    }
                }
            }
        }
        for (auto&node:ans) {
            node++;
        }
        return ans;
    }
};
// @lc code=end

