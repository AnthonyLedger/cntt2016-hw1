# LeftRightDigitsGame2

作者：陈通 陈俊锟

关键词：动态规划 记忆化搜索

## 试题来源

Topcoder SRM 556 Div1 500



## 试题大意

你现在有一叠纸牌，共$$n$$张，用$$digits$$表示，每张纸牌上写有一个数字。你每次取出牌堆顶部的第一张牌，把它放在桌子上。从第二张牌开始，你每次必须把牌放在桌上已有纸牌的最左侧或最右侧。最终这$$n$$张牌组成了一个$$n$$位数。现在给定一个$$n$$位数$$lowerBound$$，希望你求出大于等于$$lowerBound$$的可能结果中最小的一个$$n$$位数。

$$1 \leq n \leq 50$$



## 算法介绍

### 算法一

我们可以发现，牌堆顶部的连续$$i$$张牌，在这个$$n$$位数中也一定是连续的$$i$$位。我们对操作逆向考虑。每次对于牌堆底部的每一张牌，考虑放在左侧还是放在右侧。若我们已知前$$i$$张牌在$$n$$位数中所对应的区间，当我们决定了第$$i$$张牌的位置，那么我们就可以确定前$$i-1$$张牌的区间了。

定义状态$$f[i][j][s1][s2]$$，表示所求n位数中$$[1, i - 1]$$位组成的数与$$lowerBound$$中$$[1, i - 1]$$位组成的数的大小关系为$$s1$$，所求n位数中$$[j+1, n]$$位组成的数与$$lowerBound$$中$$[j+1, n]$$位组成的数的大小关系为$$s2$$，用牌堆中前$$j - i + 1$$张牌，放在$$[i, j]$$的位置上所组成最小的$$j - i + 1$$位数，满足所组成的$$n$$位数与$$lowerBound$$的大小关系满足题意。其中$$s1$$和$$s2$$用$$0, 1, 2$$分别表示小于、等于和大于关系。所求即为$$f[1][n][1][1]$$。对于状态$$f[i][j][s1][s2]$$，分别枚举第$$j - i + 1$$放在位置$$i$$和位置$$j$$两种情况，对于每种情况求出新的大小关系$$s1'$$和$$s2'$$，$$f[i][j][s1][s2]$$可以根据$$f[i + 1][j][s1'][s2]$$和$$f[i][j - 1][s1][s2']$$求出。当$$i = j$$时，我们很容易判断当前状态是否满足题意，若不满足题意则进行标记，否则该状态为牌堆第一张牌所写数字。

状态总数为$$n^2 \cdot 3^2$$。每个状态转移时，字符串比较和赋值的时间复杂度为$$O(n)$$。总时间复杂度为$$O(n^3)$$。

### 算法一的一种更详细的描述

考虑将操作串倒着往前做，我们看到最后一个操作串只可能在最终串的开头或者结尾，删掉以后最终串还是一个连续的区间。可以设计一个状态，$$f(i, l, r, s)$$ 表示操作串倒着做到第 $$i$$ 位时，最终串剩下的区间为$$(l,r)$$，一个状态（后面提到）为 $$s$$时，字典序最小的情况。注意到对于两个状态，$$[1,l]$$ 字典序越小越好，如果两个状态的 $$[1,l]$$ 相等，则 $$[r,n]$$ 的字典序越小越好。因此我们可以用一个 ```pair<string,string>``` 来保存状态。我们设一个状态中，L 为最终序列的前缀（即 $$[1,l]$$），R 为最终序列的后缀（即 $$[r,n]$$）。

我们考虑有多少种合法的情况：

1. L 的字典序严格大于相同位置上的 $$lowerBound$$ 的前缀。那么我们就希望 R 越小越好。

2. L 的字典序刚好等于相同位置上的 $$lowerBound$$ 的前缀。这时也有两种情况：

  1. 在 $$(l,r)$$ 的区间里面将会有严格大于 $$lowerBound$$  的情况，那么这是我们也希望 R 越小越好。

  2. 在 $$(l,r)$$ 的区间里面的字典序也与 $$lowerBound$$ 的大小相同，那么此时我们希望 R 在满足大于等于 $$lowerBound$$ 对应位置的情况下尽可能的小。

接下来我们规定状态 $$f(i,l,r,s)$$ 中的 $$s$$：1.的情况 $$s=0$$，2.1 的情况 $$s=1$$，2.2 的情况为 $$s=2$$。有了这几种情况我们就可以转移：（以下我考虑的是主动转移的情况）

1. 如果已经有严格大于t的前缀了，那么剩下的序列就可以直接转移，只要使得字典序最小就好了。

  $$ f(i,l,r,0) \rightarrow f(i-1.l+1,r,0) $$

  $$ f(i,l,r,0) \rightarrow f(i-1,l,r-1,0) $$

2. 我们再考虑 L 刚好顶 $$lowerBound$$ 的下界，R 不一定顶 $$lowerBound$$ 的下界的情况怎么来转移。

  1. 我们先考虑将 $$digits_i$$ 这个字符放前面：

    1. 如果 $$digits_i>lowerBound_l$$，那么把这个字符放前面时，原来顶着 $$lowerBound$$ 的下界的就会变成严格大于的（即变成了状态 0 ），于是：

      $$f(i,l,r,1) \rightarrow f(i-1,l+1,r,0)$$

    2. 如果 $$digits_i=lowerBound_l$$，那么原来顶 $$lowerBound$$ 的下界的现在还是顶着 $$lowerBound$$ 的下界：

      $$f(i,l,r,1) \rightarrow f(i-1,l+1,r,1)$$

    3. 如果 $$digits_i< lowerBound_l$$，此时这个字符放前面的情况不成立，不转移。

  2. 我们再来考虑一下 $$digit_i$$ 字符放后面：

    1. 如果 $$digit_i>lowerBound_r$$，那么这个字符放后面以后就可以使得原来不是严格大于的R后缀必然大于所构造串的等位后缀。

      $$f(i,l,r,1) \rightarrow f(i-1,l,r-1,2)$$

    2. 对于任意情况，我们都可以将这个字符直接扔在后面来转移给 $$s=1$$。

      $$ f(i,l,r,1) \rightarrow f(i-1,l,r-1,1)$$

    3. 最后是L和R都顶 $$lowerBound$$ 的下界的情况。

      1. 我们先考虑将 $$digit_i$$ 这个字符放前面：

        1. 如果 $$digit_i>lowerBound_l$$，那么把这个字符放前面时，原来顶着 $$lowerBound$$ 的下界的就会变成严格大于的（即变成了状态 $$s=0$$），于是：

          $$f(i,l,r,2) \rightarrow f(i-1,l+1,r,0)$$

        2. 如果 $$digit_i=lowerBound_l$$ ，那么原来顶 $$lowerBound$$ 的下界的现在还是顶着 $$lowerBound$$ 的下界，(R顶着 $$lowerBound$$ 的下界的情况也属于R不一定顶着 $$lowerBound$$ 的下界的情况，所以也可以转移给1)：

          $$ f(i,l,r,2) \rightarrow f(i-1,l+1,r,2) $$

          $$ f(i,l,r,2) \rightarrow f(i-1,l+1,r,1) $$

        3. 如果 $$digit_i< lowerBound_l$$ ，此时这个字符放前面的情况不满足条件，不转移。

      2. 我们再来考虑一下 $$digit_i$$ 字符放后面：

        1. 如果 $$digit_i\ge lowerBound_r$$ ，那么这个字符放后面R仍然是大于等于t的同位后缀。

          $$ f(i,l,r,2) \rightarrow f(i-1,l,r-1,2) $$

        2. 对于任意情况，我们都可以将这个字符直接扔在后面来转移给1的情况，（理由同 3.1.2 的括号内内容）。

          $$ f(i,l,r,2) \rightarrow f(i-1,l,r-1,1) $$

最后统计答案时，统计字典序最小的所有 $$f(1,i,i-1,0/2)$$ 和满足条件的 $$f(1,i,i-1,1)$$ 即可。时间复杂度为 $$O(n^3)$$。

### 算法二

如果把数字看作字符串，那么这就是一个和字典序有关的问题，我们可以考虑按位确定。

#### 简化问题

首先考虑一个简化的问题，就是给出 $$digits$$，要求通过在左侧（称为 L 操作）或右侧（称为 R 操作）添加构造一个字典序最小的数（不需要大于等于 $$lowerBound$$）。如果我们按高位到低位枚举了一个前缀 $$pre$$，满足至少存在一个包含 $$pre$$ 为前缀的 串 $$s$$ 可以通过上述方式构造，那么我们可以从小到大枚举这一位的数字 $$d$$，判断是否至少存在一个包含 $$pre+d$$ 为前缀的串 $$s$$ 可以通过上述方式构造出。一旦找到一个可行的 $$d$$，则令 $$pre\gets pre+d$$，并确定下一位。现在，问题就转化为如何判断一个前缀 $$p$$ 是否合法。

考虑可构造出的串是由什么构成的：分为 3 段，刚开始的一段全部由 L 操作产生，中间是初始字符 O 即 $$digits$$ 的第一位，末尾一段全部由 R 操作产生。则我们枚举的一个前缀将会是以下情况：

```
LLLLLLLLLORRRRRRRRRXXXXXXX
```

L、R、O 表示这个数字是通过哪一个操作得到的，末尾的 X 表示还没有确定的前缀。注意到最靠近 O 的数字来自于最早的操作，也就是说 L 这一段的**最终**顺序和这些 L 操作的**执行**顺序**相反**。对于我们的判定，如果这个前缀 $$p$$ 可以只由 L 和 O 部分构成，则判定成功，这只需要判定 $$p$$ 的**反串**是否是 $$digits$$ 的子序列即可。

如果没有，则我们就要考虑一般情况了。枚举 O 在 $$p$$ 中的位置，那么我们可以把 $$p$$ 分为 3 段，称它们为 $$pl$$、$$po$$、$$pr$$，则如果我们枚举了 O 的位置 $$po$$，那么 $$p$$ 的一般情况如下：

```
123456789OABCDEFGHI
```
把 $$p$$ 还原回 $$digits$$ 去看，那么可能会是以下情况：

```
O123456HI78G9XXXFEXDCXXBXXAX
```
如果将 $$pr$$ 在 $$digits$$ 中匹配，那么它们一定是**最早的**若干个 R 操作，而一个数不是 L 操作就是 R 操作，所以直到 $$pr$$ 在序列中匹配完毕，即

```
O123456HI78G9
```

这个位置（设为 $$k$$），那么 $$digits[1,k]$$ 每一个数的操作都确定了。而 $$k$$ 前面的 L 操作影响的是 $$pl$$ 的后半段，因此我们知道：**在 $$pr$$ 匹配完毕之前，所有的位置不是和 $$pr$$ 匹配，就是和 $$pl$$ 反串匹配**。

得到这个性质后，我们就可以匹配了。设布尔数组 $$f(i, l)$$ 表示 $$digits[1,i]$$ 中，$$pr$$ 已经匹配到了第 $$l$$ 位、第 $$pl$$ 的反串已经匹配到了第 $$i-l$$ 位是否可行。转移只需要枚举 $$i$$ 是匹配给哪一个串即可了。

匹配完毕后，考虑后半部分

```
XXXFEXDCXXBXXAX
```

如果状态 $$f(k, |pr|)$$ 可行，那么我们只需要判断 $$digits[k+1,n]$$ 中，是否包含 $$pl$$ 的反串的 $$[k-|pr|,|pl|]$$ 作为子序列即可。由于子序列有贪心性质，我们可以直接由 $$pl$$ 反串倒着从后往前匹配，求出最迟匹配位置即可。

这个算法一次判定的复杂度是 $$O(n^3)$$（枚举 O 然后匹配），总复杂度是 $$O(n^4)$$，但复杂度非常不满，可以通过所有数据。

#### 一般问题

此时要考虑必须大于等于 $$lowerBound$$，如果我们直接按照上述方式按位确定（仅考虑是否顶 $$lowerBound$$ 的下界），这里可能会错误地得到无解，如 $$digits=0165, $$lowerBound=0246$$ 时，在第 1 位判断 0 成功后，第 2 位无论判断什么都会失败，则程序返回无解。然而事实上我们完全可以构造出 $$1$$ 开头的解。

这个错误在于我们只判定了前缀能否构造，而没有判断是否能构造并且后面也能满足限制。我们可以考虑把按位确定改为 DFS 爆搜。这样看似暴力，实际上判断失败当且仅当 $$p$$ 顶着 $$lowerBound$$ 的下界，因此回溯只会进行不超过 1 次，复杂度仍然是 $$O(n^4)$$。

这个算法复杂度高达 $$O(n^4)$$，然而复杂度非常不满，可以 1MS 内通过 TC 的每个数据。
