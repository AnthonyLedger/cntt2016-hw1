# PiecewiseLinearFunction
作者：承君阳

关键词：模拟 扫描线
## 题目简述

给定长度为$$n$$数组$$Y$$表示一个连续分段函数$$f(x)$$的所有顶点$$(i,Y_i)$$，问对于所有的$$y$$，$$f(x)=y$$的根最多有多少个。

$$2 \leq n \leq 50;|Y_i| \leq 10^9 .$$

## 算法

考虑用扫描线从下往上扫描，显然，我们可以通过一个端点与它左右的大小关系来判断扫描线经过该点时和经过该点后线上的值出现次数的变化量，用map直接维护即可。

时间复杂度为$$O(nlogn)$$。
