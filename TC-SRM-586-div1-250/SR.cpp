
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

const int N = 50 + 5;
PI a[N];
class PiecewiseLinearFunction  
{  
        public:  
        int maximumSolutions(vector <int> Y)  
        {  
        	int n = Y.size();
        	FOR(i, n) a[i] = MP(Y[i], 0);
        	REP(i, 0, n - 2) 
				if (a[i].FT < a[i + 1].FT) --a[i + 1].SC, ++a[i].SC;
				else if (a[i].FT > a[i + 1].FT)--a[i].SC, ++a[i + 1].SC;
					 else return -1;
			sort(a, a + n);
			
			//����Ƕ˵�ȡֵ�Ĵ� 
			int now = 0, ans = 0;
			FOR(i, n) now += a[i].SC, cmax(ans, now);
			
			//����˵�ȡֵ�Ĵ� 
			FOR(i, n){
				int now = 0;
				REP(j, 1, n - 1) if (Y[i] > Y[j - 1] && Y[i] < Y[j] || Y[i] < Y[j - 1] && Y[i] > Y[j]) ++now;
				FOR(j, n) if (Y[i] == Y[j]) ++now;
				cmax(ans, now);
			}
			return ans;
        }  

};  

