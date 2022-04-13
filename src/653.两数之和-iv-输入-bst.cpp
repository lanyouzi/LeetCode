/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    vector<int> flag;
    vector<int> nums;
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        this->flag[root->val + 1e4]++;
        this->nums.emplace_back(root->val + 1e4);
        if (root->left != nullptr) {
            this->traverse(root->left);
        }
        if (root->right != nullptr) {
            this->traverse(root->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        this->flag.resize(2e4 + 5, 0);
        k = k + 2e4;
        this->traverse(root);
        bool ans = false;
        for (auto& item : this->nums) {
            cout << item << endl;
            if (k >= item && k - item < this->flag.size() && k-item != item && this->flag[k - item] > 0) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
