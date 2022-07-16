/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        int ans;
        int cnt = 1;        // 当前层数的剩余节点
        int layer_cnt = 1;  // 当前层数的所有节点
        while (!q.empty()) {
            TreeNode* p = q.front();
            if (cnt==layer_cnt) {
                ans = p->val;
            }
            q.pop();
            cnt--;
            if (p->left != nullptr) {
                q.emplace(p->left);
            }
            if (p->right != nullptr) {
                q.emplace(p->right);
            }
            if (cnt==0) {
                cnt = q.size();
                layer_cnt = q.size();
            }
        }
        return ans;
    }
};
// @lc code=end
