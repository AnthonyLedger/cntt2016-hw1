
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
struct Edge{ int nxt, to; } e[N * 2];
int hd[N], tail, n;

void add(int x, int y){
	e[++tail] = (Edge){hd[x], y}, hd[x] = tail;
	e[++tail] = (Edge){hd[y], x}, hd[y] = tail;
}
class HatRack  
{  
        public:  
        LL dfs(int x, int f, int i){
        	int tot = 0, l = 0, r = 0;
        	DFOR(now, x, y) if (y != f) r = l, l = y, ++tot;
        	if (tot > 2) return 0;//������������˵�����Ϸ����� 
        	
        	//��ǰ�ڵ�����������ӣ�����ö��ƥ�䷽ʽ 
        	if (i * 2 <= n && i * 2 + 1 <= n){
        		if (tot == 2) return dfs(l, x, i * 2) * dfs(r, x, i * 2 + 1) + dfs(l, x, i * 2 + 1) * dfs(r, x, i * 2);
        		return 0;
			}
			//��ǰ�ڵ����һ������ 
			if (i * 2 <= n){
				if (tot == 1) return dfs(l, x, i * 2);
				return 0;
			}
			//û�к��� 
			if (tot == 0) return 1;
			return 0;
		}
        long long countWays(vector <int> knob1, vector <int> knob2)  
        {  
        	n = knob1.size(), tail = 0, MEM(hd, 0);
        	FOR(i, n) add(knob1[i], knob2[i]);
        	++n;
        	
        	LL ans = 0;
        	//ö�ٺ�1ƥ��ĸ� 
        	REP(rt, 1, n) ans += dfs(rt, 0, 1);
        	
			return ans;        	
        }  
        
};  

