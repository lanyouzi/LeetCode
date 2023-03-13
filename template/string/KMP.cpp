/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2022-09-29 11:21:49
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-11 10:48:34
 * @FilePath: \LeetCode\templates\KMP.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;

// 由于不包含当前索引，需要额外的-1标识
vector<int> init_exclude(const string& pat) {
    int n = pat.size();
    vector<int> next(n, 0);
    next[0] = -1;
    int j = 0, k = -1;  // j表示当前索引，k表示最长公共前后缀长度
    while (j < n - 1) {
        if (k == -1 || pat[j] == pat[k]) {
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}
// combine with init (exclude)
int kmp_exclude(const string& txt, const string& pat) {
    int i = 0, j = 0;
    vector<int> next = init_exclude(pat);
    while (i < txt.size() && j < pat.size()) {
        if (txt[i] == pat[j]) {  // 进入该循环时必有j>=0
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == -1) {
            i++;
            j++;
        }
    }
    return j >= pat.size() ? i - pat.size() : -1;
}
// include current index (commonly used)
// next[i] 表示包含当前位的公共前缀长度
vector<int> init_include(const string& pat) {
    int n = pat.size();
    vector<int> next(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = next[i - 1];
        while (j>0 && pat[i] != pat[j])
            j = next[j - 1];
        if (pat[i] == pat[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}
// combine with init (include)
int kmp_include(const string& txt, const string& pat) {
    int tlen = txt.size(), plen = pat.size();
    int i = 0, j = 0;
    vector<int> next = init_include(pat);
    while (i < tlen && j < plen) {
        // 公共前缀串长度为0，重新匹配模式串
        // 当前字符相符，后进一位
        if (j == -1 || txt[i] == pat[j]) {
            i++;
            j++;
        } else {
            j = next[j] - 1;
        }
        if (j==plen) {
            return i-plen;
        }
    }
    return -1;
}

// 另一种KMP写法
vector<int> find_occurrences(const string& txt, const string& pat) {
  string cur = pat + '#' + txt;
  int tlen = txt.size(), plen = pat.size();
  vector<int> v;
  vector<int> next = init_include(cur);
  for (int i = plen + 1; i <= tlen + plen; i++) {
    if (next[i] == plen)
      v.push_back(i - 2 * plen);
  }
  return v;
}

int main() {
    string s = "abbabdabbabe";
    string pat = "abbabe";
    for (auto item : pat) {
        cout << item << '\t';
    }
    cout << endl;
    auto v = init_exclude(pat);
    for (auto item : v) {
        cout << item << '\t';
    }
    cout << endl;
    auto v2 = init_include(pat);
    for (auto item : v2) {
        cout << item << '\t';
    }
    cout << endl << kmp_include(s, pat) << " " << kmp_exclude(s, pat);
    return 0;
}