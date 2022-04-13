/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
   public:
    int maxConsecutiveChar(string& answerKey, int k, char c) {
        int ans = 0;  // max length of slicing window
        int sum = 0;  // number of the other answer
        int left = 0, right = 0;
        while (right < answerKey.size()) {
            if (answerKey[right] != c) {
                sum++;
            }
            if (sum > k) {
                if (answerKey[left] != c) {
                    sum--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
                   maxConsecutiveChar(answerKey, k, 'F'));
    }
};
// @lc code=end
