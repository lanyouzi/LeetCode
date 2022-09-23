/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> int2idx;
        for (int i=0; i<arr.size(); i++) {
            int2idx[arr[i]] = i;
        }
        for (auto& piece : pieces) {
            for (int j=0; j<piece.size(); j++) {
                if (int2idx.find(piece[j])==int2idx.end()) {
                    return false;
                }
                if (j>0) {
                    if (int2idx[piece[j-1]]!=int2idx[piece[j]]-1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

