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
    vector<int> ans;
    int max_occur;
    map<int, int> mp;
    int getSubTreeSum(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        return root->val + getSubTreeSum(root->left) + getSubTreeSum(root->right);
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        int sum = getSubTreeSum(root);
        mp[sum]++;
        if (mp[sum]>max_occur) {
            max_occur = mp[sum];
            ans.clear();
            ans.push_back(sum);
        } else if (mp[sum]==max_occur) {
            ans.push_back(sum);
        }
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        ans.clear();
        max_occur = 0;
        dfs(root);
        return ans;

    }
};
// @lc code=end

// class Solution {
//     unordered_map<int, int> cnt;
//     int maxCnt = 0;

//     int dfs(TreeNode *node) {
//         if (node == nullptr) {
//             return 0;
//         }
//         int sum = node->val + dfs(node->left) + dfs(node->right);
//         maxCnt = max(maxCnt, ++cnt[sum]);
//         return sum;
//     }

// public:
//     vector<int> findFrequentTreeSum(TreeNode *root) {
//         dfs(root);
//         vector<int> ans;
//         for (auto &[s, c]: cnt) {
//             if (c == maxCnt) {
//                 ans.emplace_back(s);
//             }
//         }
//         return ans;
//     }
// };
