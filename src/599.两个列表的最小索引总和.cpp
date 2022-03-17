/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        vector<string> ans;
        int index = INT_MAX;
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); i++) {
            string str = list1[i];
            mp[str] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            string str = list2[i];
            if (mp.count(str) > 0) {
                int ci = mp[str] + i;
                if (ci < index) {
                    index = ci;
                    ans.clear();
                    ans.emplace_back(str);
                } else if (ci == index) {
                    ans.emplace_back(str);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
