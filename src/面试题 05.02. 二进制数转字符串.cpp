/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        double cur = 0, plus = 1;
        while (cur<num) {
            if (ans.size()>=32) {
                return "ERROR";
            }
            plus = plus/2;
            if (cur+plus<=num) {
                ans+='1';
                cur+=plus;
            } else {
                ans+='0';
            }
        }
        return ans;

    }
};