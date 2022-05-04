/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return insert(grid, 0, 0, n - 1, n - 1);
    }
    Node* insert(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] != grid[r1][c1]) {
                    return new Node(
                        true, false,
                        insert(grid, r1, c1, (r1 + r2) / 2, (c1 + c2) / 2),
                        insert(grid, r1, (c1 + c2) / 2 + 1, (r1 + r2) / 2, c2),
                        insert(grid, (r1 + r2) / 2 + 1, c1, r2, (c1 + c2) / 2),
                        insert(grid, (r1 + r2) / 2 + 1, (c1 + c2) / 2 + 1, r2,
                               c2));
                }
            }
        }
        return new Node(grid[r1][c1], true);
    }
};
// @lc code=end
