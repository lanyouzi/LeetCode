/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-04 16:05:37
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-08 15:25:22
 * @FilePath: DoublePointers.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;

/*
双指针中用到了左右两个指针移动的思路是：以右指针作为驱动，拖着左指针向前走。右指针每次只移动一步，而左指针在内部while循环中每次可能移动多步。右指针是主动前移，探索未知的新区域；左指针是被迫移动，负责寻找满足题意的区间。

模板的整体思想是：

1. 定义两个指针 left 和 right 分别指向区间的开头和结尾，注意是闭区间；定义 sums用来统计该区间内的各个字符出现次数；
2. 第一重 while 循环是为了判断 right指针的位置是否超出了数组边界；当 right 每次到了新位置，需要增加 right指针的求和/计数；
3. 第二重 while 循环是让 left 指针向右移动到 [left, right]区间符合题意的位置；当 left 每次移动到了新位置，需要减少 left 指针的求和/计数；
4. 在第二重 while 循环之后，成功找到了一个符合题意的 [left, right]区间，题目要求最大的区间长度，因此更新 res 为 max(res, 当前区间的长度)。 
5. right指针每次向右移动一步，开始探索新的区间。 
模板中的 sums需要根据题目意思具体去修改，本题是求和题目因此把sums定义成整数用于求和；如果是计数题目，就需要改成字典用于计数。当左右指针发生变化的时候，都需要更新sums。
 */

int doule_pointers(vector<int>& nums, int condition) {
    // 数组长度
    int n = nums.size();
    // 双指针，表示当前遍历的区间为[left, right]（闭区间）
    int left = 0, right = 0;
    // 定义变量统计，子区间是否有效
    int sum = 0;
    // 定义变量动态保存的最大值
    int ans = 0;
    // 当右指针没有搜索到数组结尾
    while (right < n) {
        // 右移一步右指针
        sum += nums[right];
        // 当在该区间内 sum 超出定义范围
        while (sum > condition) {
            // 先将左指针指向的数值减去
            sum -= nums[left];
            // 左指针右移
            left++;
        }
        // 到 while 结束时，我们找到了一个符合题意要求的子数组/子串
        ans = max(ans, right - left + 1);
        // 移动右指针，去探索下一个区间
        right++;
    }
}
int main() {
    return 0;
}