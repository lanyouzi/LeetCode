/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-04-18 10:56:05
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-04-18 10:56:38
 * @FilePath: 1026.节点与其祖先之间的最大差值.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int ans;

    void dfs(TreeNode* root, int max_val, int min_val) {
        if (!root) {
            ans = max(ans, max_val-min_val);
            return;
        }
        dfs(root->left, max(max_val, root->val), min(min_val, root->val));
        dfs(root->right, max(max_val, root->val), min(min_val, root->val));
        
    }
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        dfs(root, INT_MIN, INT_MAX);
        return ans;
    }
};
// @lc code=end

