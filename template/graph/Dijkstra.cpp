/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-25 15:25:22
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-13 15:02:46
 * @FilePath: Dijkstra.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/***
 * @Author: lanyouzi mrk_lanyouzi@yeah.net
 * @Date: 2023-02-02 16:06:38
 * @LastEditors: lanyouzi mrk_lanyouzi@yeah.net
 * @LastEditTime: 2023-02-02 16:07:12
 * @FilePath: /LeetCode/templates/Dijkstra.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& edges) {
    vector<int> dist(n, INT_MAX);       // distance of each path (i.e. 0->X)
    vector<bool> is_visited(n, false);  // indicates whether the node is visited
    dist[0] = 0;
    is_visited[0] = true;
    for (auto edge : edges) {
        if (edge[0] == 0) {
            dist[edge[1]] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        // select the node with the min distance in unvisited nodes
        int min_dist = INT_MAX;
        int node = 0;
        for (int j = 0; j < n; j++) {
            if (!is_visited[j] && dist[j] != -1 && dist[j] < min_dist) {
                min_dist = dist[j];
                node = j;
            }
        }
        // update path distance after adding a new node
        is_visited[node] = true;
        // search nodes
        for (auto edge : edges) {
            if (edge[0] == node && !is_visited[edge[1]]) {
                if (dist[edge[1]] > dist[node] + 1) {
                    dist[edge[1]] = dist[node] + 1;
                }
            }
        }
    }
    return dist;
}