/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    int max_cnt;
    map<int, int> mp;   // <sum, num>

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = root->val + dfs(root->left) + dfs(root->right);
        mp[sum]++;
        max_cnt = max(max_cnt, mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for (auto &[x, y]:mp) {
            if (y==max_cnt) {
                ans.emplace_back(x);
            }
        }
        return ans;
    }
};
