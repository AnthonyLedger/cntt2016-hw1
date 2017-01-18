#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>
#define N 233
using namespace std;
bitset<N>f[N][N],g[N][N],T;//ѹλbitset 
struct node
{int x,y;}W[N],B[N];
node operator -(const node &x,const node &y)
{return (node)
{x.x-y.x,x.y-y.y};}//�������� 
long long xj(node x,node y)
{return (long long)x.x*y.y-(long long)x.y*y.x;}//������ 
int w,b;
struct CheckerFreeness
{
	string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY)
	{
		string S;
		int i,j,k,x,y,now,tmp;
		//���봦��ʼ 
		S="";now=0;tmp=0;
		for(i=0;i<whiteX.size();i++)
		S+=whiteX[i];
		S+=" ";
		for(i=0;i<S.size();i++)
		{
			if(S[i]==' ') w++,tmp++,W[tmp].x=now,now=0;
			else now=now*10+S[i]-48;
		}
		S="";now=0;tmp=0;
		for(i=0;i<whiteY.size();i++)
		S+=whiteY[i];
		S+=" ";
		for(i=0;i<S.size();i++)
		{
			if(S[i]==' ') tmp++,W[tmp].y=now,now=0;
			else now=now*10+S[i]-48;
		}
		S="";now=0;tmp=0;
		for(i=0;i<blackX.size();i++)
		S+=blackX[i];
		S+=" ";
		for(i=0;i<S.size();i++)
		{
			if(S[i]==' ') b++,tmp++,B[tmp].x=now,now=0;
			else now=now*10+S[i]-48;
		}
		S="";now=0;tmp=0;
		for(i=0;i<blackY.size();i++)
		S+=blackY[i];
		S+=" ";
		for(i=0;i<S.size();i++)
		{
			if(S[i]==' ') tmp++,B[tmp].y=now,now=0;
			else now=now*10+S[i]-48;
		}
		//���봦����� 
		for(i=1;i<=w;i++)
		{
			for(j=1;j<=w;j++)
			{
				for(k=1;k<=b;k++)
				f[i][j][k]=(xj(W[i]-W[j],B[k]-W[j])>0);
			}//����װ׺ڵ���� 
			for(j=1;j<=b;j++)
			{
				for(k=1;k<=b;k++)
				g[i][j][k]=(xj(W[i]-B[j],B[k]-B[j])>0);
			}//����׺ںڵ���� 
		}
		//ȫ����bitsetѹλ 
		for(i=1;i<=w;i++)
		for(j=1;j<=w;j++)
		for(k=1;k<=b;k++)
		{
			if(f[i][j][k]==0)
			T=((g[i][k]^g[j][k])&f[i][j]);
			else
			T=((g[i][k]^g[j][k])&(~f[i][j]));
			if(T.count()) return "NO";//�нⷵ��NO 
		}
		return "YES";//�޽ⷵ��YES 
	}
};