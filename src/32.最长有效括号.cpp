/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;  // stack reserves the index of the latest non-used right parent
        st.push(-1);
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(') {
                st.push(i);
            } else {    // s[i]==')'
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i-st.top()); // i-st.top() indicates the index difference of current parents
                }
            }
        }
        return ans;
    }
};
// @lc code=end

