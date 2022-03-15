/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
    void visit(Node* p, vector<int>& v) {
        if (p == nullptr) {
            return;
        }
        for (auto& child : p->children) {
            visit(child, v);
        }
        v.emplace_back(p->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        visit(root, ans);
        return ans;
    }
};
// @lc code=end
