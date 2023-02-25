/*
 * @Author: mrk-lyz mrk_lanyouzi@yeah.net
 * @Date: 2022-06-06 18:46:40
 * @LastEditors: mrk-lyz mrk_lanyouzi@yeah.net
 * @LastEditTime: 2022-06-06 20:56:07
 * @FilePath: /LeetCode/templates/BST.cpp
 * @Description:
 *
 * Copyright (c) 2022 by mrk-lyz mrk_lanyouzi@yeah.net, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
    Node(int v, Node* l, Node* r) {
        val = v;
        left = l;
        right = r;
    }
};
class BinarySearchTree {
   public:
    Node* root;
    vector<int> order;
    BinarySearchTree(const vector<int>& v) {
        int n = v.size();
        for (auto& node : v) {
            insertVal(root, node);
        }
    }
    void traverse(string method = "pre") {
        order.clear();
        if (method == "pre")
            preOrder(root);
        else if (method == "in")
            inOrder(root);
        else
            postOrder(root);
        for (auto& item : order) {
            cout << item << " ";
        }
        cout << endl;
    }
    void preOrder(Node* r) {
        if (r == nullptr) {
            return;
        }
        order.emplace_back(r->val);
        preOrder(r->left);
        preOrder(r->right);
    }
    void inOrder(Node* r) {
        if (r == nullptr) {
            return;
        }
        preOrder(r->left);
        order.emplace_back(r->val);
        preOrder(r->right);
    }
    void postOrder(Node* r) {
        if (r == nullptr) {
            return;
        }
        preOrder(r->left);
        preOrder(r->right);
        order.emplace_back(r->val);
    }
    Node* insertVal(Node*& r, int val) {
        if (r == nullptr) {
            r = new Node(val);
        } else if (val <= r->val) {
            r->left = insertVal(r->left, val);
        } else {
            r->right = insertVal(r->right, val);
        }
        return r;
    }
    Node* deleteVal(Node*& r, int val) {
        if (r == nullptr)
            return nullptr;
        if (val > r->val)  // 从右子树中寻找
            r->right = deleteVal(r->right, val);
        else if (val < r->val)  // 从左子树中寻找
            r->left = deleteVal(r->left, val);
        else {  // 当前节点就是要删除的节点
            if (!r->left)
                return r->right;  // 情况1，欲删除节点无左子
            if (!r->right)
                return r->left;     // 情况2，欲删除节点无右子
            Node* node = r->right;  // 情况3，欲删除节点左右子都有
            while (node->left)  // 寻找欲删除节点右子树的最左节点
                node = node->left;
            node->left =
                r->left;  // 将欲删除节点的左子树成为其右子树最左节点的左子树
            r = r->right;  // 欲删除节点的右子顶替其位置，节点被删除
        }
        return r;
    }
};
int main() {
    vector<int> v = {4, 1, 2, 6, 5};
    BinarySearchTree* bst = new BinarySearchTree(v);
    bst->traverse("pre");
    bst->traverse("in");
    bst->traverse("post");
    bst->deleteVal(bst->root, 4);
    bst->traverse();

    return 0;
}