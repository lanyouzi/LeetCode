/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        ans.emplace_back(vector<int>(1, root->val));
        while (!q.empty()) {
            cout << ans.size() << " " << q.size() << endl;
            int size = q.size();
            vector<int> layer;
            while (size--) {
                Node* t = q.front();
                q.pop();
                for (auto& child : t->children) {
                    q.push(child);
                    layer.emplace_back(child->val);
                }
            }
            if (layer.size() > 0) {
                ans.emplace_back(layer);
            }
        }
        return ans;
    }
};
// @lc code=end
