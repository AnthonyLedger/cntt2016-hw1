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
  
const int N = 13 + 2;
int pw[N], A[N], B[N], cur[N], f[2000000 + 5];
pair<int, int> a[N];

class MagicalHats  
{  
        public:  

        int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses)  
        {  
        	int n = 0, ans = 0;
			VEP(i, board) VEP(j, board[0]) if (board[i][j] == 'H') a[n++] = MP(i, j);
			REP(i, 0, n) pw[i] = i ? pw[i - 1] * 3 : 1;
			//����״̬ѹ��dp����ǰλΪ2��ʾδ������ñ�ӣ�1��ʾ������������Ӳ�ҵ�ñ�ӣ�0��ʾ��������Ӳ�ҵ�ñ�ӡ� 
			//״̬��ʾΪ������ǰnumGuesses�β�������ȡ�����ٸ�Ӳ�ң������-1��ô�ǲ��Ϸ�������� 
			FOR(now, pw[n]){ 
				int m = 0;
				f[now] = -1;
				FOR(i, n) cur[i] = now / pw[i] % 3;
				FOR(i, n) if (cur[i] == 2) ++m;
				if (m){
					//�������δ������ñ�ӣ�ö������δ������ñ�ӣ�����ȡ���Ž⡣ 
					FOR(i, n) if (cur[i] == 2)
						if (!~f[now - pw[i]]) cmax(f[now], f[now - 2 * pw[i]]); else
						if (!~f[now - 2 * pw[i]]) cmax(f[now], f[now - pw[i]] + (m + numGuesses > n)); else
						cmax(f[now], min(f[now - 2 * pw[i]], f[now - pw[i]] + (m + numGuesses > n)));
						//������ñ�Ӻ�������Ӳ�����������������������������ȡ�ӵĽ����
				} else {
					//����ñ�Ӿ��ѷ�������ô�жϵ�ǰ����Ƿ����Ҫ�� 
					int tot = 0;
					MEM(A, 0), MEM(B, 0);
					FOR(i, n) if (cur[i] == 0) A[a[i].FT] ^= 1, B[a[i].SC] ^= 1; else ++tot;
					if (tot == coins.size()) f[now] = 0;
					VEP(i, board) if (A[i]) {f[now] = -1; break; }
					VEP(i, board[0]) if (B[i]) {f[now] = -1; break; }
				}
			}
			sort(coins.begin(), coins.end());
			FOR(i, f[pw[n] - 1]) ans += coins[i];
			//����������������ȡ����Ӳ�Ҽ�ֵ�϶�����С�� 
			return ~f[pw[n] - 1] ? ans : -1;
        }  

};  
  
