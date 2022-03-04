# README

[toc]

## Preface

## Solution

### Dynamic Programming

1. [688] 马在棋盘上的概率
Let $dp[n][i][j]$ represent the probability of remaining on the chessboard after $n$ steps when starting at point $(i,j)$. When $(i,j)$ is not on the chessboard, $dp[n][i][j]$ is 0; specially, $dp[0][i][j]$ is $1$. The state transition equation is
$$
dp[n][i][j]=\frac{1}{8}\sum{dp[n-1][i+di][j+dj]}
$$
where $di$ and $dj$ represent the offset of coordinates.

### Divide-and-Conquer

### Graph-related