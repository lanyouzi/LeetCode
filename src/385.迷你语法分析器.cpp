/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
   public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                negative = true;
            } else if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                st.emplace(NestedInteger());
            } else if (s[i] == ',' || s[i] == ']') {
                if (isdigit(s[i - 1])) {  // avoid adding 0 when encountering
                                          // empty list
                    if (negative) {
                        num *= -1;
                    }
                    st.top().add(NestedInteger(num));
                }
                num = 0;
                negative = false;
                // if there are more than one NestedInteger, pop the top, and
                // then add it to the second.
                if (s[i] == ']' && st.size() > 1) {
                    NestedInteger ni = st.top();
                    st.pop();
                    st.top().add(ni);
                }
            }
        }
        return st.top();
    }
};
// @lc code=end
