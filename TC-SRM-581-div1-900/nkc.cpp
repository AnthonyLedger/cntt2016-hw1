#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 15
#define inf 707
using namespace std;
int n,m,a[N][N],col[N];
int ans=inf;
void dfs(int x,int now)
{
	if(now>=ans) return;
	int i,j;
	if(x==n+1)//���һ������ 
	{
		for(i=1;i<=m;i++)
		if(a[n][i]) return;//���а�ɫ�ͷ��� 
		ans=now;return;
	}
	bool must1=false,must2=false;
	int tmp=0,tmpcol[15],tmpa[15];
	for(i=1;i<=m;i++)
	tmpcol[i]=col[i],tmpa[i]=a[x-1][i];
	for(i=1;i<=m;i++)
	if(a[x-1][i])
	{
		tmp++;
		if(col[i]==1) must1=true;
		if(col[i]==2) must2=true;
	}//��must1��must2����¼��һ���Ƿ�ֻ����ĳ������ 
	if(must1&&must2) return;
	if(!must2)//�����õ�һ������ 
	{
		for(i=1;i<=m;i++)
		if(tmpa[i])
		{
			a[x-1][i]^=1,a[x][i-1]^=1,a[x][i+1]^=1,a[x+1][i]^=1;
			col[i]=1;
		}
		dfs(x+1,now+tmp);
		for(i=1;i<=m;i++)
		if(tmpa[i])
		{
			a[x-1][i]^=1,a[x][i-1]^=1,a[x][i+1]^=1,a[x+1][i]^=1;
			col[i]=tmpcol[i];
		}
	}
	if(!must1)//�����õڶ������� 
	{
		for(i=1;i<=m;i++)
		if(tmpa[i])
		{
			a[x-1][i]^=1,a[x][i-1]^=1,a[x][i+1]^=1,a[x+1][i]^=1,a[x][i]^=1;
			col[i]=2;
		}
		dfs(x+1,now+tmp);
		for(i=1;i<=m;i++)
		if(tmpa[i])
		{
			a[x-1][i]^=1,a[x][i-1]^=1,a[x][i+1]^=1,a[x+1][i]^=1,a[x][i]^=1;
			col[i]=tmpcol[i];
		}
	}
}
struct YetAnotherBoardGame
{
	int minimumMoves(vector <string> board)
	{
		n=board.size(),m=board[0].size();
		int i,j;
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		a[i][j]=(board[i-1][j-1]=='B'?0:1);//�����̱�Ϊ01������������ 
		for(i=0;i<(1<<(m+1));i+=2)//ö�ٵ�һ�е�״̬ 
		{
			int tmp=0; 
			for(j=1;j<=m;j++)
			if(i&(1<<j))
			{
				tmp++;
				a[1][j-1]^=1,a[1][j+1]^=1,a[2][j]^=1;
				col[j]=1;
			}
			dfs(2,tmp);
			for(j=1;j<=m;j++)
			if(i&(1<<j))
			{
				a[1][j]^=1;
				col[j]=2;
			}
			dfs(2,tmp);
			for(j=1;j<=m;j++)
			if(i&(1<<j))
			{
				a[1][j-1]^=1,a[1][j+1]^=1,a[2][j]^=1,a[1][j]^=1;
				col[j]=0;
			}
		}
		if(ans==inf) return -1;
		else return ans;
	}
};
int main()
{
	YetAnotherBoardGame P;
	vector<string> V;
	V.push_back("WBW");
	V.push_back("BBW");
	V.push_back("WBW"); 
	cout<<P.minimumMoves(V);
}