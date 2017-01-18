#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 105
#define M 200005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,g[N][N],vis[N],vr[N],up,down,ans;
int A[N],B[N];
void jia(int &x,int y)
{
		x+=y; if (x>=Mo) x-=Mo;
}
void work(int x,int y,int flag) //���Լ��ϵͳ,Լ����ԭ������� 
{
	int i;
	if (flag==1) 
	{
		vr[x]=1;
		B[x]=y;
		for (i=0;i<n;++i)
			if (g[i][x]!=-1)
			{
				up=max(up,y-g[i][x]+p);
				if (!vis[i])
				work(i,g[i][x]-y,0);
				else if (A[i]!=g[i][x]-y) down=-1;
			}
	}
	if (flag==0)
	{
		vis[x]=1;
		A[x]=y;
		for (i=0;i<m;++i)	
			if (g[x][i]!=-1)
			{
				int now=g[x][i]-y;
				down=min(down,now);
				if (!vr[i])
				work(i,now,1);
				else if (B[i]!=now) down=-1;
			}
	}
}
//��a����Ϸ�ʱ,�ض�����һ��(b[],c[]),����a_{i,j}=b_i+c_j,��ô�����������ж��ٵ�(b[],c[]),Ϊ��ȥ��,����Ҫ��min(b[])=0 
class EqualSums{
		public:
		int count(vector <string> board)
		{
				n=board.size(); m=board[0].length();
				for (i=0;i<n;++i) 
					for (j=0;j<m;++j)
						if (board[i][j]=='-') g[i][j]=-1;
						else g[i][j]=board[i][j]-'0';
				int s=1;
				for (i=0;i<n;++i)
					if (!vis[i])
					{
						up=0; down=1000;
						work(i,0,0); //����ÿ����ͨ��,���ĳ��Ԫ�ص����½� 
						if (up<=down)
						s=1ll*s*(down-up+1)%Mo; 
						else s=0;
					}
				jia(ans,s);
				memset(vis,0,sizeof(vis));
				memset(vr,0,sizeof(vr));
				s=1; p=1;
				for (i=0;i<n;++i)
					if (!vis[i])
					{
						up=1; down=1000;
						work(i,0,0); //�������������ܱ�֤min(b[])=0,����Ҫ��ȥmin(b[])>0����� 
						if (up<=down)
						s=1ll*s*(down-up+1)%Mo; 
						else s=0;
					}
				jia(ans,(Mo-s)%Mo);
				return ans;
		}
}MRT;

int main()
{
	  cout<<MRT.count({"-4--","-0-2","--1-","4---"});
}

