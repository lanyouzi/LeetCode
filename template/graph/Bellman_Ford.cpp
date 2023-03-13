/***
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-13 10:59:55
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-13 11:12:51
 * @FilePath: BF.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved.
 */
/*
Bellman-Ford算法是一种处理存在负权边的单元最短路问题的算法。解决了Dijkstra无法求的存在负权边的问题。其实现方式是通过m次迭代求出从源点到终点不超过m条边构成的最短路的路径。一般情况下要求途中不存在负环。但是在边数有限制的情况下允许存在负环。因此Bellman-Ford算法是可以用来判断负环的。
两种算法的关键区别就在于Dijstra是每次只对最小的节点进行操作，而Bellman-Ford是对所有节点进行操作。
*/
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;

int dist[MAXN];  // dist距离，backup用来存上一次的结果。
int n = 10, m = 20;
struct Edge
{
    int u;
    int v;
    int w;
};

int Bellman_Ford() {
    vector<int> dist(n, INT_MAX);
    vector<Edge> edge(m);
    dist[0] = 0;                        // 初始化源点距离
    for (int i = 0; i < n - 1; i++)     // 遍历（扩张）n-1次结点
    {
        for (int j = 0; j < m; j++) {   // 遍历所有边
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    return dist[n];
}