/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 1, layer_num = 0, next_layer_num = 0;
        queue<TreeNode*> q;
        q.push(root);
        layer_num++;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur->left && !cur->right) {
                return ans;
            }
            if (cur->left) {
                q.push(cur->left);
                next_layer_num++;
            }   
            if (cur->right) {
                q.push(cur->right);
                next_layer_num++;
            }
            layer_num--;
            if (layer_num==0) {
                ans++;  // 还有下一层
                layer_num = next_layer_num;
                next_layer_num = 0;
            }
                
        }
        return ans;
    }
};
// @lc code=end

