# BinPacking

作者: 徐海珂  
关键词: 贪心,枚举 

- - -

## 题目简述
Fox Ciel有$$n$$件物品。第$$i$$件(从0开始)物品的重量是$$item[i]$$。她想把所有物品都放到桶里。 每个桶可以放任意数量的物品，但是总重量不能超过$$300$$。已知每个物品重量是正整数且在$$100$$到$$300$$之间。要求出最少需要多少桶才能装下所有物品。

### 约定与限制
* $$n\le50$$
* $$item[i]\in[100,300] (0\le i<n)$$ 
* 时间限制: $$2$$s
* 空间限制: $$64$$MB

- - -

## 算法
* 由于每个物品重量在$$100$$到$$300$$之间。所以每个桶只能装$$1/2/3$$个物品。
考虑重量$$\gt 100$$的物品，他们最多只能再和一个物品装在一起了,于是把物品按升序排列，从后往前扫描枚举每一个重量$$\gt 100$$的物品$$item[i]$$,为它挑选一个最大重量$$item[j]$$($$item[j]$$不要求$$\gt 100$$)使得$$item[i]$$,$$item[j]$$可以放在一个桶里，然后把$$item[i]$$,$$item[j]$$放在一个桶里，如果找不到满足的$$item[j]$$,就让$$item[i]$$独自占一个桶。给这个桶里的物品打上标记表示已使用，然后继续上述算法。最后剩下的都是重量$$=100$$的物品，把他们每三个装一个桶就好了。

* 时间复杂度: $$O(n^2)$$
* 空间复杂度: $$O(n)$$

### 总结
* 由物品重量的特殊限制发现一个桶里能放的物品数量只有三种情况，而重量$$\gt 100$$的物品最多只能再和一个其他物品放在一起，贪心配对就好，剩下的每三个装一起就好了。

- - -

## 参考资料
* [SRM598 - TopCoder Wiki](https://apps.topcoder.com/wiki/display/tc/SRM+598)
