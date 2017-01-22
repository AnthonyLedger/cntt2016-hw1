
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

const int N = 100 + 5;
int a[N][N];
class PenguinSledding  
{  
        public:  
        long long countDesigns(int n, vector <int> x, vector <int> y)  
        {  
        	//���ѷ��ֺϷ����Ӧ����һ����Ϊ������ʣ�µ����������Ǵ���һ�������� 
        	MEM(a, 0);
        	LL ans = 0;
        	int m = x.size();
        	FOR(i, m) a[x[i]][y[i]] = a[y[i]][x[i]] = 1;
        	//ͳ�������εķ��� 
			REP(i, 1, n) REP(j, i + 1, n) REP(k, j + 1, n)
				if (a[i][j] && a[j][k] && a[k][i]) ++ans;
			//ͳ����һ����Ϊ���ĵķ��� 
			REP(i, 1, n){
				int tot = 0;
				REP(j, 1, n) if (a[i][j]) ++tot;
				ans += (1ll << tot) - 1;
			}
			//��ȥ��m���ظ�����ķ��������ϵ�1�ǿռ� 
			return ans - m + 1;
        }  
  
};  

