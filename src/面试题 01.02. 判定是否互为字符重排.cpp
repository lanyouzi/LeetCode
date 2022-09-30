class Solution {
   public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> flag(26, 0);
        int num = 0;  // non-duplicated char
        for (auto& ch : s1) {
            if (flag[ch - 'a'] == 0) {
                num++;
            }
            flag[ch - 'a']++;
        }
        for (auto& ch : s2) {
            flag[ch - 'a']--;
            if (flag[ch - 'a'] < 0) {
                return false;
            } else if (flag[ch - 'a'] == 0) {
                num--;
            }
        }
        return num == 0 ? true : false;
    }
};