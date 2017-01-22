
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
#define RUN(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define DFOR(i, x, y) for(int i = hd[x], y = e[i].to; i; i = e[i].nxt, y = e[i].to)
#define MEM(a, b) memset(a, b, sizeof(a))
#define rint read<int>()
#define rll read<LL>()

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PI;
const int inf = 0x7fffffff;
const int MOD = 1000000007;

template <typename tn>
inline tn read(){
	char ch; tn f = 1;
	while (!isdigit(ch = getchar())) if (ch == '-') f = -1;
	tn x = ch - '0';
	while (isdigit(ch = getchar())) x = x * 10 + ch - '0';
	return x * f;
}
template <typename tn> inline void cmax(tn &a, tn b){ if (a < b) a = b; }
template <typename tn> inline void cmin(tn &a, tn b){ if (a > b) a = b; }
  
const int N = 60 + 5;
LL a[N], b[N];

class XorCards  
{  
        public:  
        LL calc(int n, int m){
        	REP(i, 1, n) b[i] = a[i];
        	int now = 1, tot = 0;
        	FOR(i, m){
        		int k = 0;
        		REP(j, now, n) if (b[j] >> i & 1){k = j; break;}
        		if (!k) { ++tot; continue; }
        		swap(b[k], b[now]);
        		REP(j, now + 1, n) if (b[j] >> i & 1) b[j] ^= b[now];
        		++now;
			}
			REP(i, now, n) if (b[i]) return 0;
			return 1ll << tot;
		}
        long long numberOfWays(vector<long long> number, long long limit)  
        {  
        	//���ǽ�limit+1�����Ǿ������ֵ<limit�Ĵ𰸣���ô����ö�����ֵǰxλ��ͬ���ڵ�x+1λС��limit�� 
			//��ʵ���Ǹ���򷽳��飬��⼴�ɡ� 
        	int m = number.size(), n = 0;
        	long long ans = 0;
        	++limit; 
        	MEM(a, 0);
			ROF(i, 50){
				++n; FOR(j, m) a[n] |= (number[j] >> i & 1ll) << j;
				if (limit >> i & 1) ans += calc(n, m), a[n] |= 1ll << m;
			}
			return ans;
        }  

};  

