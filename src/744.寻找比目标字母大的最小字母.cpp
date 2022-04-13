/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = target;
        vector<bool> flag(26, false);
        for (auto& ch : letters) {
            flag[ch - 'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            cout << (target + i + 1 - 'a') % 26 << endl;
            if (flag[(target + i + 1 - 'a') % 26]) {
                ans = 'a' + (target + i + 1 - 'a') % 26;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
