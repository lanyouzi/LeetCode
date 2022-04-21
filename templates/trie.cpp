#include <bits/stdc++.h>
using namespace std;

// Triee is commonly used to generate, query sets of strings as an alternative to Map.

const int MAXN = 1e5 + 10;
int trie[MAXN][26];         // trie[i][j] represent the index of j-th child of i-th node
bool flag[MAXN];            // flag[i] represent if i-th string is a complete word
int total = 0;              // total number of words including prefix
void insert(string s)       // insert given string s into the trie
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (!trie[p][ch]) {
            total++;
            trie[p][ch] = total;
        }
        p = trie[p][ch];
    }
    flag[p] = true;
}
bool query(string s)  // query if given string s is in the trie
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
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