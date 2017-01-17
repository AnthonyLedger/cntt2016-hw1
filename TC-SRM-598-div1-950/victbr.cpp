#include <bits/stdc++.h>

using namespace std;

const int N = 60;

struct Edge{
	int end,next;
};

class TPS{
	public:
		int ans,first[N],efn,n,f[N];
		Edge edge[N<<1];
		int minimalBeacons(vector <string> linked){
			n = linked.size();ans = n;//�ڵ��0��n-1 
			if (n == 1) return 0;//ֻ��1����ʱ��Ϊ0 
			for (int i = 0;i < n;i++)	
				for (int j = i+1;j < n;j++)
					if (linked[i][j] == 'Y')
						addedge(i+1,j+1);
			for (int i = 1;i <= n;i++) {
				memset(f,0,sizeof(f));
				dp(i,0);
				ans = min(ans,f[i]+1);
			}
			return ans;
		}
		void addedge(int x,int y){
			edge[++efn].end = y;
			edge[  efn].next = first[x];
			first[x] = efn;
			edge[++efn].end = x;
			edge[  efn].next = first[y];
			first[y] = efn;
		}
		void dp(int x,int y){//ֻ��Ҷ�ӽڵ����á�������������������ʶ����ʣ�µ�һ��Ҷ�ӽڵ�����ʶ�� 
			bool flag = 0;
			for (int h = first[x];h;h = edge[h].next){
				int u = edge[h].end;
				if (u != y){
					dp(u,x);
					if (f[u] == 0) flag = 1;
					f[x] += max(1,f[u]);
				}
			}
			f[x] -= flag;
		}
}; 
