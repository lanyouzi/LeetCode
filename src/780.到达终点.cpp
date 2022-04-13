/*
 * @lc app=leetcode.cn id=780 lang=cpp
 *
 * [780] 到达终点
 */

// @lc code=start
/*
    易知，对于给定的(tx, ty)，可选操作是唯一的，即大值减去小值
    循环结束的条件为：tx<sx或ty<sy或tx==ty
    结束后再判断是否满足要求
 */
class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx == sx && ty == sy) {
            return true;
        }
        if (tx < sx || ty < sy || tx == ty) {
            return false;
        }
        if (sx == tx && sy <= ty) {
            return (ty - sy) % sx == 0;
        } else if (sy == ty && sx <= tx) {
            return (tx - sx) % sy == 0;
        }
        // 任一点都不满足要求，用较大值模较小值
        else if (tx < ty) {
            return reachingPoints(sx, sy, tx, ty % tx);
        } else {
            return reachingPoints(sx, sy, tx % ty, ty);
        }
    }
};
// @lc code=end
