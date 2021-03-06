#Egalitarianism
作者:孙奕灿

关键词:图论,最短路.

##问题简述
有一张 $$N$$ 个点的无向图,要求给每个点分配一个标号,使得任意一条边两端的点的标号差(绝对值)不能超过给出的常数 $$D$$ ,要求在此基础上最大化 标号的最大值减最小值.如果答案为 $$+\infty$$,则输出 -1.

##数据范围
$$N\leq 50$$

$$D\leq 1000$$

##算法一
如果这张图不连通,那么答案显然为$$+\infty$$,否则我们固定一个点 $$A$$ ,使它的标号为 0, 那么一个和 $$A$$ 最短距离为 $$t$$ 的点 $$B$$, 其标号必须落在 $$[-t * d, t * d]$$ 之间, 因为图连通,所以 $$t$$ 是有限的,因此答案是有限的.

从上述论证中也可以看出,$$A$$ 和 $$B$$ 的标号差的最大值就是 $$t * d$$, 因此最短路越长,标号差越大,因此答案就是 $$d * t_{max}$$, $$t_{max}$$$$ 是两两点对最短路的最大值.

用 $$floyd$$ 计算 $$$$t_{max}$$即可.

时间复杂度$$O(N^3)$$.


