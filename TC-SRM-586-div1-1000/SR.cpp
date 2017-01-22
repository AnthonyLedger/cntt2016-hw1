
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

const int N = 50 + 5;
int f[N][N][N];
int calc(int A, int B, int C, int D, int l){
	if (D) return (B * (B + 1)) / 2 + (C * (C - 1)) / 2 + D * l;
	else return (B * (B + 1)) / 2 + (C * (C - 1)) / 2 + l - min(l, 26);
}
class StringWeight  
{  
        public:  
        int getMinimum(vector <int> L)  
        {  
        	int n = L.size();
        	
        	MEM(f, 0x3f);
        	f[0][0][0] = 0;
        	//f[i][j][k]��ʾ����ǰi���Ӵ���ʹ�ù�j���ַ�����k��������ʹ�õķ�����
			//ת��ʱ����ö��
			//1.���������ܴ���Ψһһ�γ��֡�
			//2.���������ܴ��е�һ�γ��֣�����Ψһһ�Σ���
			//3.���������ܴ������һ�γ��֣�ͬ�ϣ���
			//4.��Ȳ��������ܴ��е�һ�γ��֣�Ҳ�������һ�� ��
			//��������ĸ����� 
        	FOR(i, n) REP(j, 0, 26) REP(k, 0, j) if (f[i][j][k] < inf){
        		int tmp = min(L[i], 26);
        		REP(A, 0, min(26 - j, tmp)) REP(B, 0, min(26 - j - A, tmp - A)) 
					if (tmp - A - B <= j - k) REP(C, 0, min(26 - k - A, tmp - A - B)){
        				int D = j - k - C;
        				cmin(f[i + 1][j + A + B][k + A + C], f[i][j][k] + calc(A, B, C, D, L[i]));
        			}
        	}
        	int ans = inf;
        	REP(i, 0, 26) cmin(ans, f[n][i][i]);
        	return ans;
        }  
    
};  

