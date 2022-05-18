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
    vector<TreeNode*> v;
    void dfs(TreeNode* r) {
        if (r == nullptr) {
            return;
        }
        dfs(r->left);
        v.emplace_back(r);
        dfs(r->right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        dfs(root);
        for (int i = 0; i < v.size(); i++) {
            if (p->val == v[i]->val) {
                if (i < v.size() - 1)
                    ans = v[i + 1];
            }
        }
        return ans;
    }
};