/***
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-13 11:20:39
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-13 11:22:45
 * @FilePath: Floyd.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved.
 */

/*
可以计算出任意两点之间的最小距离，允许图中包含负权边。
算法步骤：
1.建立一个矩阵map来存储只经过一条边时，两点之间的距离，本质上和邻接矩阵相同。
2.记录经过某一个固定顶点后两点之间的距离。
3.共需要更新矩阵n次（n为节点个数）
 */
#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<vector<int>> Floyd(vector<vector<int>> &matrix) {
    vector<vector<int>> dist(matrix);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    return dist;
}

using namespace std;
int main() {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    auto dist = Floyd(matrix);
    
    return 0;
}