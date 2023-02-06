/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    set<int> st;
    void dfs(TreeNode* root) {
        if (root==nullptr) {
            return;
        }
        st.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        dfs(root);
        if (st.size()>1) {
            return false;
        } else {
            return true;
        }
    }
};
// @lc code=end

