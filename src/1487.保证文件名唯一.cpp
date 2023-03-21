/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
class Solution {
public:
    string addSuffix(string name, int k) {
        return name + "(" + to_string(k) + ")";
    }

    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> res;
        for (const auto &name : names) {
            if (!mp.count(name)) {      // 未出现
                res.push_back(name);
                mp[name] = 1;
            } else {                    // 出现过
                int k = mp[name];
                while (mp.count(addSuffix(name, k))) {  // 找到不存在的最小后缀k
                    k++;
                }
                res.push_back(addSuffix(name, k));
                mp[name] = k + 1;
                mp[addSuffix(name, k)] = 1;
            }
        }
        return res;
    }
};
// @lc code=end

