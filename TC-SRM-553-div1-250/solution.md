# Suminator
���ߣ����
�ؼ��ʣ��������������ۡ�ջ

## ��Ŀ����
����һ��ջ����������������������$$0$$��
����һ������$$n$$���Ǹ�������������$$program$$�����ζ����ջ���в�����
�����ǰ��������$$0$$���ͰѸ���ѹ��ջ�
�����ǰ����Ϊ$$0$$����ô�Ͱ�ջ���������������������������ĺ�ѹ��ջ�
����һЩ��Ϣȱʧ������Ĳ��������������ҽ���һ������δ֪�ģ���$$-1$$��ʾ��������������Ǹ�������
�����ڸ��������в�������ջ������$$wantedResult$$������δ֪�����������޽⣬һ���⣬������⣩

���ݷ�Χ��$$1\le n\le 50,-1\le program_{i}\le 10^{9},1\le wantedResult\le 10^{9}$$

## ���

���ǲ������з��ࣺ
  1��**δ֪��Ϊ0��** ������ģ��ѹջ��ջ�Ĺ��̼��ɵõ�δ֪���Ƿ�Ϊ0��
  2��**δ֪����Ϊ0��** ���ѷ���ջ��������һЩ���ĺͣ�������ģ��ѹջ��ջ�Ĺ��̱�ɵõ���Щ����������Ĵ𰸣����յõ�����һ������$$ax=b��a=0/1$$����ôʣ�µľ��ǽ�һԪһ�η��̵������ˡ�����$$a$$��ϵ���������ֿ��������·��ࣨ~~����Сѧ������ö�����ҲҪд��~~����
    1.$$a=0$$����ô���$$b=0$$������⣬$$b\neq 0$$���޽⡣
    2.$$a=1$$����ô$$a$$��Ψһ�⣬����$$a=b$$��
ʱ�临�Ӷ���ռ临�ӶȾ�Ϊ$$O(n)$$

## ����

```C++
#include<bits/stdc++.h>
#define FT first
#define SC second
#define PB push_back
#define MP make_pair
#define REP(i, l, r) for(int i = (l); i <= (r); i++)
#define PER(i, r, l) for(int i = (r); i >= (l); i--)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define ROF(i, n) for(int i = (n) - 1; i >= 0; i--)
#define VEP(i, x) for(int i = 0; i < x.size(); i++)
#define DFOR(i, x, y) for(int i = hd[x], y = e[i].to; i; i = e[i].nxt, y = e[i].to)
#define RUN(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define MEM(a, b) memset(a, b, sizeof(a))
#define rint read<int>()
#define rll read<LL>()

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PI;
const int inf = 0x7fffffff;
const int MOD = 1000000007;

template <typename tn> inline void cmax(tn &a, tn b){ if (a < b) a = b; }
template <typename tn> inline void cmin(tn &a, tn b){ if (a > b) a = b; }


class Suminator  
{  
        public:  
        int findMissing(vector <int> program, int wantedResult)  
        {  
            reverse(program.begin(), program.end());

            int cnt, found = 0; LL tot;
            
            cnt = 1, tot = 0;            
            RUN(i, program){
                if (*i == 0 || *i == -1) ++cnt;
                else if (--cnt >= 0) tot += *i;
                if (cnt == 0) break;
            }
            if (tot == wantedResult) return 0;
            
            //unknown number = 0 
            cnt = 1, tot = 0;
            RUN(i, program){
                if (*i == 0) ++cnt;
                else if (--cnt >= 0) if (*i > 0) tot += *i; else found = 1;
                if (cnt == 0) break;
            }
            
            //unknown number != 0
            LL x = wantedResult - tot;
            if (!found)//the coefficient of unknown number = 0 
                if (x) return -1;
                else return 1;
            else//the coefficient of unknown number = 1
                if (x >= 1 && x <= 1000000000) return x;
                else return -1;
        }  
};  
```

