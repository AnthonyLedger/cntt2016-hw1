#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define mp(a,b,c,d) (make_pair(make_pair(make_pair(a,b),c),d))
#define can(x,y) (x>=0&&x<n&&y>=0&&y<m)
using namespace std;
map<pair<pair<pair<int,int>,int>,int>,int>P;
struct CoinsGame
{
	int f[2][41][41];
	int tot[1610],cf[1610];
	static const int mod=1e9+9;
	int ways(vector <string> board)
	{
		int n=board.size(),m=board[0].size();
		int i,j,o=0,cn;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		f[0][i][j]=1;//һ��ʼ���е��״̬��1 
		while(1)
		{
			bool nc=true;
			cn=0;
			P.clear();
			o^=1;
			for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				int t1,t2,t3,t4;
				if(can(i-1,j))
				{
					if(board[i-1][j]=='#') t1=f[o^1][i][j];//����߲����ˣ����ĺ��״̬���Լ� 
					else t1=f[o^1][i-1][j];//���߶�����ͳ�ƺ��״̬ 
				}
				else t1=0;//��������״̬Ϊ0 
				if(can(i+1,j))
				{
					if(board[i+1][j]=='#') t2=f[o^1][i][j];
					else t2=f[o^1][i+1][j];
				}
				else t2=0;
				if(can(i,j-1))
				{
					if(board[i][j-1]=='#') t3=f[o^1][i][j];
					else t3=f[o^1][i][j-1];
				}
				else t3=0;
				if(can(i,j+1))
				{
					if(board[i][j+1]=='#') t4=f[o^1][i][j];
					else t4=f[o^1][i][j+1];
				}
				else t4=0;
				if(!P[mp(t1,t2,t3,t4)]) cn++,P[mp(t1,t2,t3,t4)]=cn;//ֱ����ɢ�� 
				f[o][i][j]=P[mp(t1,t2,t3,t4)];
				if(f[o][i][j]!=f[o^1][i][j]) nc=false;
			}
			if(nc) break;
		}
		//���ֻ��Ҫ�ü򵥵���ѧ���ɾͿ���ͳ�ƴ� 
		int TOT=0;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		if(board[i][j]=='.')
		tot[f[o][i][j]]++,TOT++;
		cf[0]=1;
		for(i=1;i<=TOT;i++)
		cf[i]=cf[i-1]*2%mod;
		int ans=cf[TOT]-1;
		for(i=1;i<=cn;i++)
		(ans-=cf[tot[i]]-1)%=mod;
		return (ans+mod)%mod;
	}
};