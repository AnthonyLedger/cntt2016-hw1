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

#define N 55
#define M 200005
#define seed 23333

using namespace std;
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
int i,j,m,n,p,k,cnt,col[N][N],Min[N*N],Max[N*N],deg[N][N];
int LU[N],LD[N],RU[N],RD[N],LR[N],f[N][N][N];
char s[N][N]; 
int dp() //Ȼ������ת��Ϊ,ÿ��λ���Ͽ�����(��),�������ƥ����ٸ����� 
{ 
	 int a,b;
	 memset(f,-1,sizeof(f));
	 f[0][0][0]=0; //�Ѿ���j����ߵ�(,k���ұߵ�)���ƥ��Ķ��� 
	 for (i=0;i<n;++i)
	 	for (j=0;j<=i;++j)
	 		for (k=0;k<=i;++k)
	 			if (f[i][j][k]!=-1)
	 			{
	 					for (a=-1;a<=1;++a)
	 						for (b=-1;b<=1;++b)
	 						{
	 								if (a==-1&&!LU[i+1]) continue;
	 								if (a==1 &&!LD[i+1]) continue;
	 								if (b==-1&&!RU[i+1]) continue;
	 								if (b==1 &&!RD[i+1]) continue;
	 								if (a==b&&a&&LR[i+1]) continue;
	 								if (a+j>=0&&b+k>=0)
	 								f[i+1][a+j][b+k]=max(f[i+1][a+j][b+k],f[i][j][k]+(a==-1)+(b==-1));
	 						}
	 			}
	  return f[n][0][0];
}
int check(int x,int y)
{
		if (x<1||y<1||x>n||y>m||col[x][y]||s[x][y]=='.') return 0;
		return 1;
}
void dfs(int x,int y)
{
		int i;
		Min[cnt]=min(Min[cnt],x);
		Max[cnt]=max(Max[cnt],x);
		col[x][y]=cnt;
		for (i=0;i<4;++i)
			if (check(x+X[i],y+Y[i])) dfs(x+X[i],y+Y[i]);
}
class Tunnels{
	public:
	int minimumTunnels(vector <string> frame)
	{
		memset(Min,60,sizeof(Min));
		memset(Max,-1,sizeof(Max));
		n=frame.size(); m=frame[0].length();
		for (i=1;i<=n;++i) 
			for (j=1;j<=m;++j) s[i][j]=frame[i-1][j-1];
		for (i=1;i<=n;++i) //�������ÿ����ͨ���Լ�ÿ����Ķ���,��ҪҪ��߽��ϵ�Ķ��� 
			for (j=1;j<=m;++j)
			{
				if (s[i][j]=='X'&&!col[i][j])
				++cnt,dfs(i,j);
				for (k=0;k<4;++k)
					if (s[i+X[k]][j+Y[k]]=='X') ++deg[i][j];
			}
		if (m==1) return cnt>0;
		for (i=1;i<=n;++i)
		{
				if (col[i][1]&&deg[i][1]<=1) //���������߽��ҽ���һ��������ȥ,��ô��������
				/* X
				   X �� XX
				 */ 
				{
						if (Min[col[i][1]]==i) LU[i]=1; //�������ͨ��������ĵ�������ڱ߽����������� 
						if (Max[col[i][1]]==i) LD[i]=1; //��������ĵ�ͬ�� 
				}
				if (col[i][m]&&deg[i][m]<=1) //�Ҳ�ͬ�� 
				{
						if (Min[col[i][m]]==i) RU[i]=1;
						if (Max[col[i][m]]==i) RD[i]=1;
				}
				if (col[i][1]==col[i][m]&&col[i][1]) LR[i]=1; //�������һ����,��ô�ȿ�������Ҳ��������,�ȿ������Ҳ�����Ҳ� 
		}
		for (i=3;i<=n;++i) //�������һ����������,������
			/*...
			  X..
			  X..
			  ...		��ô����ĵ���һ���������������,����ͻ�ײ�� 
			*/ 
		{
				if (LU[i-1]) LD[i]=0;
				if (RU[i-1]) RD[i]=0;
		}
		for (i=2;i<=n;++i)
			//�������
				// .......
				// XXX....
				// ....... ��ô��������ǲ������µ� 
				if (col[i][1]!=col[i][m])
				{
						if (col[i][1]&&Min[col[i][1]]==Max[col[i][1]]) LD[i]=0;
						if (col[i][m]&&Min[col[i][m]]==Max[col[i][m]]) RD[i]=0;
				}
		return cnt-dp();
	}
}MRT;

int main()
{
	 cout<<MRT.minimumTunnels({"X.XX",
 "X...",
 "...X",
 "X...",
 "X..X"});
}

