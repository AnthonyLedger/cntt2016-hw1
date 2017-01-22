
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
const int inf = 0x3f3f3f3f;
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

const int N = 1000000 + 5;
int fac[N], ind[N], cnt[N], ans[N], f[N];
//ɸ����С������ 
void prework(){
	int n = 1e6;
	MEM(fac, 0);
	REP(i, 2, n) if (!fac[i]) REP(j, 1, n / i) fac[i * j] = i;
}
//Ԥ����ÿ��p^c������Сֵ�� 
void work(int p, int c, int n){
	REP(i, 0, n) cnt[i] = 0, f[i] = inf;
	ind[0] = c, ind[1] = 0;
	REP(i, 2, n) ind[i] = i % p ? 0 : ind[i / p] + 1; 
	REP(k, 0, p * c){
		int tmp = (LL)k * k % n;
		for (int j = 0, i = (tmp + j) % n; j != n; j += p, i = (tmp + j) % n){
			if (cnt[i] < c && cnt[i] + ind[j] >= c) f[i] = k;
			cnt[i] += ind[j];
		}
	}
}
//��1-n�У�����mod d==i������ 
LL calc(LL n, int d, int i){
	if (i == 0) return n / d;
	else return n / d + (n % d >= i);
}
LL solve(LL n, LL d){
	LL tmp = 0;
	FOR(i, d) if (ans[i] < inf && (LL)ans[i] * ans[i] < n)
		tmp += calc(n, d, i) - calc((LL)ans[i] * ans[i], d, i);
	return tmp;
}
class SparseFactorial  
{  
        public:  
        long long getCount(long long lo, long long hi, long long d)  
        {  
        	MEM(ans, 0);

			//��ÿ�������ӷֿ�����        	
        	prework();
			int tmp = d;
			while (tmp > 1){
				int p = fac[tmp], c = 0, p_c = 1;
				while (!(tmp % p)) tmp /= p, ++c, p_c *= p;
				work(p, c, p_c);
				//����ȡ���ֵ�� 
				FOR(i, d) cmax(ans[i], f[i % p_c]); 
			}
			return solve(hi, d) - solve(lo - 1, d);
        }  
     
};  

