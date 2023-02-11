# README

[TOC]

## Preface

1. 数组不变，求区间和：「前缀和」、「树状数组」、「线段树」
2. 多次修改某个数（单点），求区间和：「树状数组」、「线段树」
3. 多次修改某个区间，输出最终结果：「差分」
4. 多次修改某个区间，求区间和：「线段树」、「树状数组」（看修改区间范围大小）
5. 多次将某个区间变成同一个数，求区间和：「线段树」、「树状数组」（看修改区间范围大小）

具体而言：

- 简单求区间和，用「前缀和」
- 多次将某个区间变成同一个数，用「线段树」
- 其他情况，用「树状数组」

## Solution

### Greedy

1. [769] 最多能完成排序的块

### Dynamic Programming

1. [688] 马在棋盘上的概率
   Let $dp[n][i][j]$ represent the probability of remaining on the chessboard after $n$ steps when starting at point $(i,j)$. When $(i,j)$ is not on the chessboard, $dp[n][i][j]$ is 0; specially, $dp[0][i][j]$ is $1$. The state transition equation is
   
   $$
   dp[n][i][j]=\frac{1}{8}\sum{dp[n-1][i+di][j+dj]}
   $$
   
   where $di$ and $dj$ represent the offset of coordinates.

2.[1223] 投骰子模拟

### Binary Search

1. [668]乘法表中第k小的数
   由于 mm 和 nn 很大，直接求出所有数字然后找到第 kk 小会超出时间限制。不妨考虑一个反向问题：对于乘法表中的数字 xx，它是乘法表中第几小的数字？
   求第几小等价于求有多少数字不超过 xx。我们可以遍历乘法表的每一行，对于乘法表的第$i$行，其数字均为$i$的倍数，因此不超过$x$的数字有$min(\lfloor\frac{x}{i}\rfloor,n)$个，所以整个乘法表不超过$x$的数字个数为
   
   $$
   \sum_{i=1}^{m}min(\lfloor\frac{x}{i}\rfloor,n)
   $$
   
   由于$i\le\lfloor\frac{x}{n}\rfloor$时有$\lfloor\frac{x}{i}\rfloor\ge n$，上式可简化为
   
   $$
   \lfloor\frac{x}{n}\rfloor\cdot n+\sum_{i=\lfloor\frac{x}{n}\rfloor+1}^{m}\lfloor\frac{x}{i}\rfloor
   $$
   
   由于$x$越大上式越大，因此可以二分$x$查找答案。二分的初始边界为乘法表的元素范围，即$[1,mn]$。

### Tree-Related

#### BST（二叉搜索树）

1. [450]删除二叉搜索树中的节点

#### Segment Tree（线段树）

#### Trie（字典树）

1. [440]字典序的第k小数字
2. [1233]删除子文件夹

### Graph-related

### BFS

1. [310]最小高度树：从度为1的点开始BFS
2. [854]相似度为k的字符串：每次交换不同的字符
3. [1129]颜色交替的最短路径
4. [1210]穿过迷宫的最少移动次数

#### Binary Index Tree（树状数组）

树状数组支持两种操作：`单点修改`（更改数组中一个元素的值）和`区间查询`（查询一个区间内所有元素和），时间复杂度均为O(logn)。

1. [307]区域和检索-数组可修改

### Divide-and-Conquer

### Monotone Priority Stack

### Number Theory

1. [172]阶乘后的零
   [1, n]中质因子p的个数为
   
   $$
   \sum^{\infty}_{k=1}{\lfloor \frac{n}{p^k} \rfloor}
   $$

### Double Pointers

1. [11]盛最多水的容器
2. [15]三数之和
3. [16]最接近的三数之和
4. [436]寻找右区间

### Slicing Window

1. [30]串联所有单词的子串
2. [713]乘机小于k的子数组
3. [1004]最大连续-1-的个数-iii
4. [2024]考试的最大困扰度

### Algorithm

#### Aho-Corasick Automaton

1. Construct Trie Tree
2. Construct Fail Point(BFS)

## Operation

### Bit Manipulation

- 计算整数x的二进制表示有多少个1：`x&x-1`可以消除x最低位的1，while循环计数，直到x=0即可。
- 只保留整数x最低位的1：`x&-x`，即树状数组中的lowbit
