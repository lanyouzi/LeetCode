class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        vector<vector<int>> ans;
        for (auto& interval:intervals) {
            mp[interval[0]]++;
            mp[interval[1]]--;
        }
        int pre, cur = 0;
        for (auto& [x, y]:mp) {
            if (cur == 0) {
                pre = x;
            }
            cur = cur + y;
            if (cur == 0) {
                ans.push_back({pre, x});
            }
        }
        return ans;

    }
};