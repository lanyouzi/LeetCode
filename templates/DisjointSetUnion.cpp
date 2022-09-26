#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
class DSU {
   public:
    vector<int> pre;
    vector<int> rank;

    DSU(int maxn) {
        pre.resize(maxn);
        rank.resize(maxn);
        fill(pre.begin(), pre.end(), -1);
        fill(rank.begin(), rank.end(), 1);
    }
    // find the root node of value
    int find(int value) {
        while (pre[value] != -1) {
            value = pre[value];
        }
        return value;
    }
    // change the parent index of each node in searching path
    int find_improved(int value) {
        if (pre[value] == -1) {
            return value;
        }
        pre[value] = find(value);
        return pre[value];
    }
    // merge the given two nodes
    void join(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx==ry) {
            return;
        }
        if (rank[x]>rank[y]) {
            pre[y] = x;
        } else {
            if (rank[x]==rank[y]) {
                rank[y]++;
            }
            pre[x] = y;
        }
    }
};
int main() {
    return 0;
}