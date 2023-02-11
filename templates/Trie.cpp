#include <bits/stdc++.h>
using namespace std;

// Trie is commonly used to generate, query sets of strings as an alternative to Map.


// array version
const int MAXN = 1e5 + 10;
int trie[MAXN][26];         // trie[i][j] represent the index of j-th child of i-th node
bool flag[MAXN];            // flag[i] represent if i-th string is a complete word
int total = 0;              // total number of words including prefix
void insert(string s)       // insert given string [s] into the trie
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
bool query(string s)  // query if given string [s] is in the trie
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
bool startwith(const string& s)  // query if there is string starting with current given [s] in the trie
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

// pointer version
class Trie {
public:
    int flag; // flag为i（非-1）表示该节点是代表第i个完整元素
    unordered_map<string, Trie*> children;
    Trie(): flag(-1) {
    }
};

void insert(Trie* root, const vector<string> &strs, int i) {
    for (const string& str:strs) {
        if (!root->children.count(str)) {
            root->children[str] = new Trie();
        }
        root = root->children[str];
    } 
    root->flag = i;
}

// 判断strs是否为某一序列
bool startswith(Trie* root, const vector<string> &strs) {
    for (auto str:strs) {
        if (!root->children.count(str)) {
            return false;
        }
        root = root->children[str];
    }
    return root->flag;
}

// 判断strs是否为某一前缀
bool startswith(Trie* root, const vector<string> &strs) {
    for (auto str:strs) {
        if (!root->children.count(str)) {
            return false;
        }
        root = root->children[str];
    }
    return true;
}

// traverse all elements
void dfs(Trie* root) {
    if (root->flag!=-1) {
        cout << "No. " << root->flag << " element exists." << endl;
    }
    for (auto&& [_, child]:root->children) {
        dfs(child);
    }
}