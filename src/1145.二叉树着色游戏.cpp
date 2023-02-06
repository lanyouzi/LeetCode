/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
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
    int getNodeNum(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        return 1+getNodeNum(root->left)+getNodeNum(root->right);
    }
    void findNode(TreeNode* root, TreeNode* &node, int x) {
        if (root==nullptr) {
            return;
        } else if (root->val==x) {
            node = root;
            return;
        }
        findNode(root->left, node, x);
        findNode(root->right, node, x);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* node = root;
        findNode(root, node, x);
        cout << node->val << endl;
        int left_num = getNodeNum(node->left);
        int right_num = getNodeNum(node->right);
        int parent_num = n-left_num-right_num-1;
        int threshold = (n-1)/2;
        if (left_num>threshold || right_num>threshold || parent_num> threshold) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

