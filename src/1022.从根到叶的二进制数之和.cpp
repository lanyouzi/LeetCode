/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int num;
    void dfs(TreeNode* r, string s) {
        s = s + to_string(r->val);
        if (r->left == nullptr && r->right == nullptr) {
            num += stoi(s, 0, 2);
            return;
        }
        if (r->left != nullptr) {
            dfs(r->left, s);
        }
        if (r->right != nullptr) {
            dfs(r->right, s);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        num = 0;
        dfs(root, "");
        return num;
    }
};
// @lc code=end
