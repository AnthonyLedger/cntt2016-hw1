
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

int a[2], b[2];
int pw(int x, int k){ int s = 1; for(; k; k >>= 1, x = (LL)x * x % MOD) if (k & 1) s = (LL)s * x % MOD; return s; }
class DefectiveAddition  
{  
        public:  
        int count(vector <int> cards, int n)  
        {  
        	//���ѷ����������һ�����������Ͻ磬��ô��Ϊʣ��������+1��ĳ˻���
			//�����ɸߵ���λ���ǣ����һ����һ����ȡֵС���Ͻ��ˣ���ô���Ǳ��ֱ�Ӽ���𰸡�
        	int can = 1, ans = 0;
        	//����ö������С���Ͻ��λ�ã�����ͳ�Ƽ��� 
        	ROF(i, 31){
        		a[0] = 1, a[1] = 0;
        		int flag = 0, sum = 1;
				VEP(j, cards){
					flag ^= cards[j] >> i & 1;
					b[0] = b[1] = 0;
					FOR(k, 2) b[k] = (b[k] + (LL)a[k ^ (cards[j] >> i & 1)] * ((cards[j] & ((1 << i) - 1)) + 1)) % MOD;
					if (cards[j] >> i & 1) FOR(k, 2) b[k] = (b[k] + (LL)a[k] * (1 << i)) % MOD;
					FOR(k, 2) a[k] = b[k];
					sum = (LL)sum * ((cards[j] & ((1 << i) - 1)) + 1) % MOD;
				}        		
				ans = (ans + LL(a[n >> i & 1] - (sum * (flag == (n >> i & 1)))) * pw((1 << i), MOD - 2)) % MOD;
				can &= (flag == (n >> i & 1));
				if (!can) break;
			}
			return (ans + can + MOD) % MOD;
        }  
  
};  

