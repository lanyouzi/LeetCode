/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    void visit(Node* p, vector<int> &v) {
        if (p==nullptr) {
            return;
        }
        v.emplace_back(p->val);
        for (auto& child:p->children){
            visit(child, v);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        visit(root, ans);
        return ans;
    }
};
// @lc code=end

