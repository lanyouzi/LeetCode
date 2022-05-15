# README

[toc]

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

### Dynamic Programming

1. [688] 马在棋盘上的概率
Let $dp[n][i][j]$ represent the probability of remaining on the chessboard after $n$ steps when starting at point $(i,j)$. When $(i,j)$ is not on the chessboard, $dp[n][i][j]$ is 0; specially, $dp[0][i][j]$ is $1$. The state transition equation is
$$
dp[n][i][j]=\frac{1}{8}\sum{dp[n-1][i+di][j+dj]}
$$
where $di$ and $dj$ represent the offset of coordinates.

### Tree-Related

### BFS

1. [310]最小高度树：从度为1的点开始BFS

#### Trie（字典树）

1. [440]字典序的第k小数字

#### Binary Index Tree（树状数组）

树状数组支持两种操作：`单点修改`（更改数组中一个元素的值）和`区间查询`（查询一个区间内所有元素和），时间复杂度均为O(logn)。

1. [307]区域和检索-数组可修改

### Graph-related

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

### Slicing Window

1. [713]乘机小于k的子数组
2. [1004]最大连续-1-的个数-iii
3. [2024]考试的最大困扰度

### Algorithm

#### Aho-Corasick Automaton

1. Construct Trie Tree
2. Construct Fail Point(BFS)

### Operation

#### Int

- 计算整数x的二进制表示有多少个1：`x&x-1`可以消除x最低位的1，while循环计数，直到x=0即可。
- 只保留整数x最低位的1：`x&-x`，即树状数组中的lowbit
