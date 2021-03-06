# MayTheBestPetWin

作者：袁宇韬

关键词：动态规划

## 题目简述

有$$n$$个独立的随机变量，第$$i$$个变量可能为$$a_i$$到$$b_i$$之间的任意实数值。将这些随机变量分为两组，使得两组变量的和的差的绝对值的最大值最小。求出这个最小值。

## 算法一

令$$S$$和$$T$$为分成的两个集合。答案为


$$
\begin{align}
&\max(\sum_{i \in S} b_i - \sum_{i \in T} a_i, \sum_{i \in T} b_i -
\sum_{i \in S} a_i) \\
&= \max(\sum_{i=0}^{n-1} b_i - \sum_{i \in T} (a_i + b_i), \sum_{i \in
T} (a_i + b_i) - \sum_{i=0}^{n-1} a_i)
\end{align}
$$


因此答案只与某一部分中的$$a_i + b_i$$的和有关。可以用DP求出可能得到的$$a_i + b_i$$的和，再求出答案。

时间复杂度$$O(n \sum_{i=0}^{n-1} (a_i + b_i))$$。

