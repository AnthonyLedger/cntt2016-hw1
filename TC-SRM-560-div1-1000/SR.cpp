
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
  
const int N = 14 + 5;
int a[N][N], pw[N];
double b[N], x[N];

class BoundedOptimization  
{  
        public:  
        double maxValue(vector <string> expr, vector <int> lb, vector <int> ub, int S)  
        {  
        	MEM(a, 0);
        	int l = 0, r = 0;
        	VEP(i, expr) VEP(j, expr[i])
        		if (expr[i][j] == '+') a[l][r] = a[r][l] = 1;
        		else l = r, r = expr[i][j] - 'a';
        	a[l][r] = a[r][l] = 1;
        	
			int n = lb.size();
			pw[0] = 1;
			REP(i, 1, n) pw[i] = pw[i - 1] * 3;
			
			double ans = 0;
			//3^n�η�ö�٣�0��ʾ����ֵ��1��ʾȡ��Сֵ��2��ʾȡ���ֵ 
        	FOR(now, pw[n]){
        		vector<int> cur;
        		MEM(b, 0), MEM(x, 0);
        		FOR(i, n)
					if (now / pw[i] % 3 == 0) cur.PB(i); 
					else{
						x[i] = (now / pw[i] % 3 == 1 ? lb[i] : ub[i]);
						FOR(j, n) if (a[i][j]) b[j] += x[i];
					}
					
				//�������������������ֵ֮��ϵ��Ϊ0����ô���ѷ�������һ���Ĵ𰸿���ȡ����ֵ�������������ǲ���Ҫ���ǵ�
				//�����ж�֮����ϵ��Ϊ0����ֱ������������ 
				int flag = 1;
				VEP(i, cur)	VEP(j, cur) if (i != j && a[cur[i]][cur[j]] == 0) flag = 0;
				
				if (flag){
					double s = S;
					FOR(i, n) s -= x[i];
					
					//����������ֵ֮�䣬���ǲ���ͨ��������Ը�����ж�Ӧȡֵ�� 
					if (cur.size()){
						VEP(i, cur) s -= b[cur[i]] - b[cur[0]];
						s /= cur.size();
						VEP(i, cur) x[cur[i]] = s + b[cur[i]] - b[cur[0]];
					}
					
					//�ж�ȡֵ�Ƿ�Ϸ���Ȼ����´𰸡� 
					double tot = 0;
					int flag = 1;
					FOR(i, n) tot += x[i];
					FOR(i, n) if (x[i] + 1e-10 < lb[i] || x[i] > ub[i] + 1e-10) flag = 0;
					if (tot <= S + 1e-10 && flag){
						double tmpans = 0;
						FOR(i, n) FOR(j, n) if (i < j && a[i][j]) tmpans += x[i] * x[j];
						cmax(ans, tmpans);
					}	
				}
			}
			return ans;
        }  
   
};  

