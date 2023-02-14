/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
public:
    // 单调栈+前缀数组
    // 二维循环遍历和大于0的最长子串
    // 1.为什么单调递减：遍历外层循环时，若i<j<k且prefix[i]<prefix[j]，则j~k一定不会是答案，栈中存储候选i；
    // 2.为什么栈：在向左遍历内层j时，若prefix[st.top()]>prefix[j]，则可以直接省略栈顶元素。
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int ans = 0;
        int left = 0, right = 0;
        vector<int> nums(n, 0);
        vector<int> prefix(n+1, 0);
        for (int i=0; i<n; i++) {
            nums[i] = hours[i]>8?1:-1;
        }
        for (int i=1; i<=n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for (auto p:prefix) {
            cout << p << " ";
        }
        cout << endl;
        stack<int> st;      // monotonically decreasing stack
        for (int i=0; i<n; i++) {
            if (st.empty() || prefix[st.top()]>prefix[i]) {
                st.push(i);
            }
        }
        while (!st.empty()) {
            auto i = st.top();
            st.pop();
            for (int j=n; j>i; j--) {           // judge j from right to left
                if (prefix[j]-prefix[i]>0) {    // if j satisfies condition, no need to search a shorter substring
                    ans = max(ans, j-i);
                    continue;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

