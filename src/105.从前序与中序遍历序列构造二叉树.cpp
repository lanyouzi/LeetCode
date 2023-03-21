/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    map<int, int> mp;

    TreeNode* build(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if (l1>r1 || l2>r2) {
            return nullptr;
        }
        int root_num = preorder[l1];
        int mid = mp[root_num];
        TreeNode* root = new TreeNode(root_num);
        int left_size = mid-l2;
        root->left = build(preorder, l1+1, l1+left_size, inorder, l2, mid-1);
        root->right = build(preorder, l1+1+left_size, r1, inorder, mid+1, r2);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
};
// @lc code=end

