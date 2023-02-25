/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // 设xy对n个，yx对m个
        // 相同对子交换只需一次，不同对子交换要两次，优先交换相同对子
        if (s1.size()!=s2.size()) {
            return -1;
        }
        int xy = 0, yx = 0;
        for (int i=0; i<s1.size(); i++) {
            if (s1[i]=='x' && s2[i]=='y') {
                xy++;
            } else if (s1[i]=='y' && s2[i]=='x') {
                yx++;
            }
        }
        if ((xy&1)^(yx&1)) {    //  最低位不同，无法满足要求
            return -1;
        }
        return (xy>>1)+(yx>>1)+((xy&1)<<1);

    }
};
// @lc code=end

