/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-08 16:27:20
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-08 19:29:46
 * @FilePath: \LeetCode\src\1233.删除子文件夹.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end(), [&](string s1, string s2)-> bool {return s1<s2;});
        ans.emplace_back(folder[0]);
        string prefix = folder[0];
        for (int i=1; i<folder.size(); i++) {
            if (folder[i].find(prefix)!=0 || folder[i][prefix.size()]!='/') {
                // not prefix
                ans.emplace_back(folder[i]); 
                prefix = folder[i];
            }
        }
        return ans;
    }
};

// LeetCode题解：字典树+dfs
struct Trie {
    Trie(): ref(-1) {}  // ref不为零表示存在该路径字符串

    unordered_map<string, Trie*> children;
    int ref;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        auto split = [](const string& s) -> vector<string> {
            vector<string> ret;
            string cur;
            for (char ch: s) {
                if (ch == '/') {
                    ret.push_back(move(cur));
                    cur.clear();
                }
                else {
                    cur.push_back(ch);
                }
            }
            ret.push_back(move(cur));
            return ret;
        };

        Trie* root = new Trie();
        for (int i = 0; i < folder.size(); ++i) {
            vector<string> path = split(folder[i]);
            Trie* cur = root;
            for (const string& name: path) {
                if (!cur->children.count(name)) {
                    cur->children[name] = new Trie();
                }
                cur = cur->children[name];
            }
            cur->ref = i;
        }

        vector<string> ans;

        function<void(Trie*)> dfs = [&](Trie* cur) {
            if (cur->ref != -1) {
                ans.push_back(folder[cur->ref]);
                return; // 直接回溯，剩余深层节点都是该节点的子文件夹。
            }
            for (auto&& [_, child]: cur->children) {
                dfs(child);
            }
        };

        dfs(root);
        return ans;
    }
};

// @lc code=end

