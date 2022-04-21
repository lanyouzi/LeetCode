#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int trie[MAXN][26]; // trie[i][j] represent j-th child of i-th node
bool flag[MAXN];      
int idx;
void insert(string s)  // insert string s into trie
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i] - 'a';
        if (!trie[p][ch]) {
            trie[p][ch] = ++idx;
        }
        p = trie[p][ch];
    }
    flag[p] = true;
}
bool query(string s)  // query if current given s is in the trie
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i] - 'a';
        if (!trie[p][ch])
            return false;
        else {
            p = trie[p][ch];
        }
    }
    return flag[p];
}
bool startwith(const string& s)  // query if there is string starting with current given s in the trie
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i] - 'a';
        if (!trie[p][ch])
            return false;
        else {
            p = trie[p][ch];
        }
    }
    return true;
}
