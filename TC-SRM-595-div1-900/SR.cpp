
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
  
inline PI operator - (const PI &a, const PI &b){ return MP(a.FT - b.FT, a.SC - b.SC); }
inline LL operator * (const PI &a, const PI &b){ return (LL)a.FT * b.SC - (LL)a.SC * b.FT; }
inline LL dot(const PI &a, const PI &b){ return (LL)a.FT * b.FT + (LL)a.SC * b.SC; }
const int N = 50 + 5;
PI a[N];
class Constellation  
{  
        public:  
        double expectation(vector <int> x, vector <int> y, vector <int> prob)  
        {  
        	//ֻ��Ҫö��һ��͹���������������ڵ������ǣ�����һ��û���κε���֣��Լ�������û�е���֡�
			//Ȼ��ֱ�ӽ�ÿ��������Ȩֵ���ϸ��ʼ���𰸼��ɡ� 
         	double ans = 0;
         	int n = x.size();
         	FOR(i, n) a[i] = MP(x[i], y[i]);
         	FOR(i, n) FOR(j, n) if (i != j) {
         		double tmp = a[i] * a[j] * 0.5 * (1.0 * prob[i] / 1000) * (1.0 * prob[j] / 1000 );
			 	FOR(k, n)if (i != j && j != k && ((a[k] - a[i]) * (a[j] - a[i]) > 0 || (a[k] - a[i]) * (a[j] - a[i]) == 0 && dot(a[i] - a[k], a[j] - a[k]) < 0))
			 		tmp *= (1.0 - 1.0 * prob[k] / 1000);
			 	ans += tmp;
			 }
			 return ans;
        }  
  
};  

