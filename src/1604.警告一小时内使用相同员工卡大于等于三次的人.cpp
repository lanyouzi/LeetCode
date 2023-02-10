/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<string>> mp;
        vector<string> names;
        for (int i=0; i<keyName.size(); i++) {
            string name = keyName[i], time = keyTime[i];
            mp[name].emplace_back(time);
        }
        for (auto &it:mp) {
            sort(it.second.begin(), it.second.end(), [&](string s1, string s2)->bool {return s1<s2;});
            int n = it.second.size();
            for (int i=0; i<n-2; i++) {
                string hour1 = it.second[i].substr(0, 2), minute1 = it.second[i].substr(3, 2);
                string hour2 = it.second[i+2].substr(0, 2), minute2 = it.second[i+2].substr(3, 2);
                if (stoi(hour2)*60+stoi(minute2)-stoi(hour1)*60-stoi(minute1)<=60) {
                    names.emplace_back(it.first);
                }
            }
        }
        vector<string>::iterator pos = unique(names.begin(), names.end());
        names.erase(pos, names.end());
        return names;
    }
};
// @lc code=end

