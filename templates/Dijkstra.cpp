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

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dist(n, -1);    // distance of each path (i.e. 0->X)
        vector<bool> is_visited(n, false);   // indicates whether the node is visited
        vector<int> color(n, 0); // 0 means init, 1 means red, 2 means blue
        dist[0] = 0;
        is_visited[0] = true;
        for (auto edge:redEdges) {
            if (edge[0]==0) {
                dist[edge[1]] = 1;
                color[edge[1]] = 1;
            }
        }
        for (auto edge:blueEdges) {
            if (edge[0]==0) {
                dist[edge[1]] = 1;
                color[edge[1]] = 2;
            }
        }
        for (int i=1; i<n; i++) {
            // select the node with the min distance in unvisited nodes
            int min_dist = 1e9;
            int node = 0;
            for (int j=0; j<n; j++) {
                if (!is_visited[j] && dist[j]!=-1 && dist[j]<min_dist) {
                    min_dist = dist[j];
                    node = j;
                }
            }
            // update path distance after adding a new node
            is_visited[node] = true;
            if (color[node]==1) {
                // search nodes with blue edges
                for (auto edge:blueEdges) {
                    if (edge[0]==node && !is_visited[edge[1]]) {
                        if (dist[edge[1]]==-1 || dist[edge[1]]>dist[node]+1) {
                            dist[edge[1]]=dist[node]+1;
                            color[edge[1]] = 2;
                        }
                    }
                }
            } else {
                // search nodes with red edges
                for (auto edge:redEdges) {
                    if (edge[0]==node && !is_visited[edge[1]]) {
                        if (dist[edge[1]]==-1 || dist[edge[1]]>dist[node]+1) {
                            dist[edge[1]]=dist[node]+1;
                            color[edge[1]] = 1;
                        }
                    }
                }
            }
        }
        return dist;
    }
};