/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
   public:
    string toGoatLatin(string sentence) {
        sentence = sentence + " ";
        string ans = "";
        int index = 1;
        bool is_capital = true;
        bool is_vowel = true;
        int left = 0, right = 0;
        while (right < sentence.size()) {
            if (sentence[right] == ' ') {
                string word = sentence.substr(left, right - left);
                left = right + 1;
                if (tolower(word[0]) == 'a' || tolower(word[0]) == 'e' ||
                    tolower(word[0]) == 'i' || tolower(word[0]) == 'o' ||
                    tolower(word[0]) == 'u') {
                    word += "ma";
                } else {
                    word = word.substr(1) + word[0] + "ma";
                }
                for (int i = 0; i < index; i++) {
                    word += "a";
                }
                ans += word;
                if (right != sentence.size() - 1) {
                    ans += ' ';
                }
                index++;
            }
            right++;
        }
        return ans;
    }
};
// @lc code=end
