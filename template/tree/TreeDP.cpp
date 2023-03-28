/***
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-13 10:25:48
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-17 10:24:57
 * @FilePath: TreeDP.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved.
 */

/*
小红拿到了一棵树，每个节点被染成了红色或者蓝色。

小红定义每条边的权值为：删除这条边时，形成的两个子树的同色连通块数量之差的绝对值。

小红想知道，所有边的权值之和是多少？

令dp[i]代表以i点为根的子树中同色联通块的个数，下标从1开始。
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
string a;
vector<int> e[maxn];    // 邻接表e
long long ans = 0;

// 令dp[i]点为根的子树中同色联通块的个数，那么如果我们从1号点开始算，最后dp[1]得到的就是整棵树的同色联通块个数。
// dp[i] = \sum{dp[j]+[color[i]!=color[j]]}
int dp[maxn];

void dfs(int u, int fa) {
    // 如上图，在dfs之前假设最开始只有u孤零零的一个点
    dp[u] = 1;
    for (int v : e[u]) {
        if (v == fa)
            continue;
        // 每次新增一个子树v，插到u上
        dfs(v, u);
        // 转移
        dp[u] += dp[v];
        if (a[u - 1] == a[v - 1])
            dp[u]--;
    }
}

void dfs1(int u, int fa) {
    for (int v : e[u]) {
        if (v == fa)
            continue;
        dfs1(v, u);
        // 计算边的贡献
        int x = dp[1] - dp[v];
        if (a[u - 1] == a[v - 1])
            x += 1;
        ans += abs(x - dp[v]);
    }
}
int main() {
    int n;
    cin >> n;
    cin >> a;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    // 第一遍dfs求出dp数组
    dfs(1, -1);
    // 第二遍dfs计算每条边的贡献
    dfs1(1, -1);
    cout << ans << endl;
    return 0;
}