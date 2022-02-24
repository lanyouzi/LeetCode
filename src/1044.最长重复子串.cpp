/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */

// @lc code=start
class Solution {
public:
unsigned long long prime = 37;
int findIndex(const string& s, int len) {
    unsigned long long hash = 0;
    unsigned long long power = 1;
    for (int i = 0; i < len; i++) {
        hash = hash * prime + (s[i] - 'a');
        power = power * prime;
    }
    unordered_set<unsigned long long> exist = {hash};
    for (int i = len; i < s.size(); i++) {
        hash = hash * prime - power * (s[i - len] - 'a') + (s[i] - 'a');
        if (exist.count(hash)) {
            return i - len + 1;
        }
        exist.insert(hash);
    }
    return -1;
}
string longestDupSubstring(string s) {
    string ans = "";
    int l = 1, r = s.size() - 1;
    int pos = -1;
    int len = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        int start = findIndex(s, mid);
        if (start != -1) {  // 出现重复子串
            len = mid;
            pos = start;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (pos != -1) {
        ans = s.substr(pos, len);
    }
    return ans;
}
};
// @lc code=end

