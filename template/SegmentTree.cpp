/*
 * @Author: mrk-lyz mrk_lanyouzi@yeah.net
 * @Date: 2022-06-21 13:39:30
 * @LastEditTime: 2022-06-21 14:05:38
 * @FilePath: /LeetCode/templates/SegmentTree.cpp
 * @Description:
 *
 * Copyright (c) 2022 by mrk-lyz mrk_lanyouzi@yeah.net, All Rights Reserved.
 */
#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
inline ll read() {
    ll ans = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}
ll n, m, A[MAXN], tree[MAXN * 4], mark[MAXN * 4];  // 经验表明开四倍空间不会越界
inline void push_down(ll p, ll len) {
    mark[p * 2] += mark[p];
    mark[p * 2 + 1] += mark[p];
    tree[p * 2] += mark[p] * (len - len / 2);
    tree[p * 2 + 1] += mark[p] * (len / 2);
    mark[p] = 0;
}
/**
 * @description: 
 * @param {ll} l: left index
 * @param {ll} r: right index
 * @param {ll} p: current index
 * @return {*}
 */
void build(ll l = 1, ll r = n, ll p = 1) {
    if (l == r)
        tree[p] = A[l];
    else {
        ll mid = (l + r) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}
/**
 * @description: 
 * @param {ll} l: target left index
 * @param {ll} r: target right index
 * @param {ll} d: increment
 * @param {ll} p: current index
 * @param {ll} cl: current left index
 * @param {ll} cr: current right index
 * @return {*}
 */
void update(ll l, ll r, ll d, ll p = 1, ll cl = 1, ll cr = n) {
    if (cl > r || cr < l)               // 区间无交集
        return;
    else if (cl >= l && cr <= r) {      // 当前节点对应的区间包含在目标区间中
        tree[p] += (cr - cl + 1) * d;
        if (cr > cl)
            mark[p] += d;
    } else {                            // 当前区间与目标区间有交集，但不包含于其中
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);      // 向下传递lazy标记
        update(l, r, d, p * 2, cl, mid);
        update(l, r, d, p * 2 + 1, mid + 1, cr);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];    // 根据子节点更新当前节点的值
    }
}
ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = n) {
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r)
        return tree[p];
    else {
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        return query(l, r, p * 2, cl, mid) +
               query(l, r, p * 2 + 1, mid + 1, cr);
    }
}
int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
        A[i] = read();
    build();
    for (int i = 0; i < m; ++i) {
        ll opr = read(), l = read(), r = read();
        if (opr == 1) {
            ll d = read();
            update(l, r, d);
        } else
            printf("%lld\n", query(l, r));
    }
    return 0;
}