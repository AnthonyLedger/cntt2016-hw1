#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 2510
#define M 125010
#define inf 707185547
using namespace std;
struct Graph
{
	int to[M],nxt[M],pre[N],w[M],cnt;
	int s,e;
	Graph()
	{cnt=1;memset(pre,0,sizeof(pre));}
	void AE(int ff,int tt,int ww)
	{
		cnt++;
		to[cnt]=tt;
		nxt[cnt]=pre[ff];
		w[cnt]=ww;
		pre[ff]=cnt;
	}
	void ae(int ff,int tt,int ww)
	{
		AE(ff,tt,ww);
		AE(tt,ff,0);
	}
	int d[N],q[N],h,t;
	bool bfs()
	{
		memset(d,0,sizeof(d));
		h=t=1;d[s]=1;
		q[1]=s;
		int i,j,x,y;
		while(h<=t)
		{
			x=q[h];h++;
			for(i=pre[x];i;i=nxt[i])
			if(w[i])
			{
				j=to[i];
				if(d[j]) continue;
				d[j]=d[x]+1;
				t++;q[t]=j;
			}
		}
		if(d[e]) return true;
		return false;
	}
	int dfs(int x,int v)
	{
		if(x==e||v==0) return v;
		int i,j,ret=0;
		for(i=pre[x];i;i=nxt[i])
		if(w[i])
		{
			j=to[i];
			if(d[j]!=d[x]+1) continue;
			int f=dfs(j,min(w[i],v));
			v-=f;
			ret+=f;
			w[i]-=f;
			w[i^1]+=f;
			if(!v) break;
		}
		if(!ret) d[x]=-1;
		return ret;
	}
	int dinic()//������ 
	{
		int ret=0;
		while(bfs())
		ret+=dfs(s,inf);
		return ret;
	}
}G;
struct FoxAndCity
{
	int n;
	int c(int x,int y)
	{
		return x*n+y;
	}
	int sqr(int x)
	{return x*x;}
	int minimalCost(vector <string> linked, vector <int> want)
	{
		n=linked.size();
		int i,j,k;
		G.s=n*n;G.e=n*n+1;
		//��ͼ���� 
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		if(linked[i][j]=='Y')
		{
			for(k=1;k<n;k++)
			G.ae(c(j,k),c(i,k-1),inf);//�б��������໥Ӱ�� 
		}
		G.ae(G.s,0,inf);
		for(j=1;j<n-1;j++)
		G.ae(j,j+1,inf);
		G.ae(n-1,G.e,inf);//0�ŵ�������Ϊ0�����⽨�� 
		for(i=1;i<n;i++)
		{
			G.ae(G.s,c(i,0),inf);
			G.ae(c(i,0),c(i,1),inf);//��������벻��Ϊ0�����⽨�� 
			for(j=1;j<n-1;j++)
			G.ae(c(i,j),c(i,j+1),sqr(j-want[i]));
			G.ae(c(i,n-1),G.e,sqr(n-1-want[i]));
		}
		return G.dinic();//����С�� 
	}
};
/*FoxAndCity P;
int main()
{
	vector<string>V1;
	V1.push_back("NYY");
	V1.push_back("YNN");
	V1.push_back("YNN");
	vector<int>V2;
	V2.push_back(0);
	V2.push_back(0);
	V2.push_back(0);
	cout<<P.minimalCost(V1,V2);
}*/