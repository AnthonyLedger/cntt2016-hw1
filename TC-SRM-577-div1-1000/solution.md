#BoardPainting

---
作者：闵梓轩（感谢南京外国语的徐懿同学对于算法正确性证明的帮助）

关键词：最小割
##题目简述
> * 一个$$n*n$$的画板上有若干个格子需要染色，每次可以选择一个起点然后沿着上下左右任意一个方向染色，每次染色不能经过不需要染色或者已经染过色的格子，染色过程中也不能改变方向，求最小化染色次数。
* 数据保证$$n\leq 50$$。

###算法一
看到这道题的要求和数据范围很容易想到利用网络流最小割建图，刚开始我通过尝试拆点并在中间连一条容量为1的边来限制染色次数，后来发现无论怎样建图都无法限制染色时不能变换方向，后来只能去参考官方题解，不幸的是官方题解并没有给出建图正确性的严谨证明。

* 我们先给出需要构建的流网络：
* $$G(V,E)：\\
V=\left\{v|v是原图中所需要染色的点\right\}+\left\{s,t\right\}，\\
E={(u,v)|c(u,v)=1，u,v是原图中所需染色的且四连通相邻的点}\\
+\left\{(s,v)|c(s,v)=v上下方向相邻的不需染色的格子数\right\}\\
+\left\{(v,t)|c(v,t)=v左右方向相邻的不需染色的格子数\right\}$$
此流网络的最小割容量（一定为偶数）的一半即为原图答案。

首先我们将画板的边缘视为一层不需染色的格子，然后将一次染色的**起止位置的两端**视为两个“边界”，那么一次正确的染色必然产生若干对横边界和纵边界。
![图](https://apps.topcoder.com/wiki/download/attachments/103449800/d110001.png)
上图中每一对边界中间的格子都是在同一次操作中被染色，而边界则切割了两个属于不同次染色的格子，或染色的格子与不需被染色的格子。如果我们将边界视为不可通过的边，那么我们有：（下面都是比较蛋疼的证明）

* 引理：一个合法（不存在未被染色的格子）的染色方案形成中不存在从某个不需染色的格子纵向出发，横向到达另一个不需染色的格子，且不经过任何边界的路径。
* 证明：如果一个合法的染色方案中存在这样一个路径，那么这个路径必然纵向进入一个格子然后从这个格子横向出发（即拐了个弯）。能够纵向进入这个格子说明这个格子不在一对纵边界中，即它不是被竖着染色的，同理可以证明它也不是被横着染色的，那么这个格子就没有被染色，这与该染色方案合法性相悖。

接下来我通过两个方面证明一个合法的染色方案与我们上面所描述的流网络中的一个极小割一一对应，极小割的定义为去掉该割（边集）中的任意一条边，该边集都不能构成一个割。

* 定理一：原图中的一个合法的染色方案对应流网络中的一个割。
* 证明：引理一中所述的路径其实就对应流网络中的一条从源点到汇点的路径，而一个合法的方案的边界切断了所有可能的路径，也就构成了流网络中的一个割集。
* 定理二：流网络中的一个极小割对应了原图的一个合法方案。
* 证明（此处感谢徐懿同学）：极小割中的点一定可被划分到两个集合$$S=\left\{v|存在从s到v的路径\right\}，T=\left\{v|存在从v到t的路径\right\}$$唯一一个。如果有任何一个点不属于两个中的任意一个，那么说明这个割不是一个极小割，如果有任何一个点同时属于两个集合；那么说明存在从源到汇的路径，这个边集不是一个割。那么$$S-\left\{s\right\}$$就是所有被横着染色的格子的集合（存在横边界），同理$$T-\left\{t\right\}$$是所有被竖着染色的格子的集合。因为不存在同属两个集合的点，所以每个格子都至多被染色了一次；同时因为不存在同时不属于两个集合的点，所以每个格子都至少被染色了一次。也就证明流网络中的一个极小割对应了原图中的一个合法方案。

上面我们证明了合法方案与极小割的对应，而一个极小割的容量其实就是边界的数量，染色次数的两倍，所以我们求出最小割（最小割一定是一个极小割）并返回其容量的一半就是原问题的答案。
