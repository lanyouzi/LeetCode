/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ans = 0;
        unordered_map<char, int> c2i{{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        vector<int> cnt(5); // 待匹配的字符数量
        int rest = 0;       // 未完成的蛙鸣数量
        for (int i=0; i<croakOfFrogs.size(); i++) {
            int cur = c2i[croakOfFrogs[i]];     // 当前字符索引
            cnt[cur]++;
            if (cur == 0) { // 新蛙鸣
                rest++;
                ans = max(ans, rest);
            } else {        // 旧蛙鸣
                cnt[cur-1]--;
                if (cnt[cur-1]<0) { // 没有待匹配的前置字符
                    return -1;
                }
                if (cur==4) {       // 尾字符
                    rest--;
                }
            }
        }
        return rest>0?-1:ans;
    }
};
// @lc code=end

