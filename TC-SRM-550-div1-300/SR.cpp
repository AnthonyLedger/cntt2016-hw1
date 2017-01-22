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
  
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};
bool a[5000 + 5][5000 + 5];
class RotatingBot  
{  
        public:  
        int minArea(vector <int> moves)  
        {  
        	//���費һ��Ҫ�����߽�Ϳ���ת��ģ�������������˶���·�ߣ���¼�����ĵ����϶ˣ�����ˣ����Ҷˣ����¶˵����꣬�Ӷ��õ���С���εı߽硣 
        	int x = 2500, y = 2500, Xmx = 2500, Xmn = 2500, Ymx = 2500, Ymn = 2500, fx = 3;
        	MEM(a, 0), a[2500][2500] = 1;//��ʼ��֮��Ҳ�޷������� 
        	RUN(it, moves){
        		fx = (fx + 1) % 4;//�任���� 
        		REP(i, 1, *it){
        			x += dx[fx], y += dy[fx];
        			if (a[x][y]) return -1;//���������֮ǰ�����ĵ㣬�򷵻�-1�� 
        			a[x][y] = 1, cmin(Xmn, x), cmax(Xmx, x), cmin(Ymn, y), cmax(Ymx, y);//���¼�ֵ�� 
				}
			}
			//��֤�Ƿ������߽��Լ�֮ǰ�����ĸ��ӲŽ���ת�� 
			x = 2500, y = 2500, MEM(a, 0), a[2500][2500] = 1, fx = 3;
			moves.pop_back();//���һ�����߿�������ͣ�£����Բ���Ҫ�жϣ������ӵ��� 
			RUN(it, moves){
        		fx = (fx + 1) % 4;
        		REP(i, 1, *it) x += dx[fx], y += dy[fx], a[x][y] = 1;
        		int tx = x + dx[fx], ty = y + dy[fx]; 
        		if (!a[tx][ty] && tx >= Xmn && tx <= Xmx && ty >= Ymn && ty <= Ymx)
        			return -1;//�ж��Ƿ������߽����ǰ�����ĸ��� 
			}
			return (Xmx - Xmn + 1) * (Ymx - Ymn + 1);
        }  
  
};  
  
