/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        set<string> st;
        for (auto& item : paths) {
            st.insert(item[1]);
        }
        for (auto& item : paths) {
            st.erase(item[0]);
        }
        return *st.begin();
    }
};
// @lc code=end
