class Solution {
public:
    // include current index (commonly used)
    // next[i] 表示包含当前位的公共前缀长度
    vector<int> init_include(const string& pat) {
        int n = pat.size();
        vector<int> next(n, 0);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j && pat[i] != pat[j])
                j = next[j - 1];
            if (pat[i] == pat[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }
    // combine with init (include)
    int kmp(const string& txt, const string& pat) {
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
        }
        // j==plen表示匹配完成
        return j == plen ? i - plen : -1;
    }
    bool isFlipedString(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 != n2) {
            return false;
        }
        if (n1==0) {
            return true;
        }
        for (int i = 0; i < n1; i++) {
            s1 += s1[i];
        }
        int pos = kmp(s1, s2);
        return pos != -1;
    }
};