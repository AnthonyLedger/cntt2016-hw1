#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 51
#define YES return "POSSIBLE"
#define NO return "IMPOSSIBLE"
using namespace std;
struct ppp
{
	int l,r;
	void update(int x)
	{
		if(!l) l=x;
		else r=x;
	}
}b[N];
int a[N],n;
int fan[N];
struct DisjointSemicircles
{
	int to[N*N],nxt[N*N],w[N*N],pre[N],cnt,cn;
	int col[N];
	bool d[N];
	void ae(int ff,int tt,int ww)//ww=0������ͬ��=1����ͬ 
	{
		cnt++;
		to[cnt]=tt;
		nxt[cnt]=pre[ff];
		w[cnt]=ww;
		pre[ff]=cnt;
	}
	bool DFS(int x,int c)//���Ը�����ͼȾɫ 
	{
		int i,j;
		col[x]=c;
		for(i=pre[x];i;i=nxt[i])
		{
			j=to[i];
			if(w[i]==1)
			{
				if(col[j])
				{
					if(col[j]!=3-col[x]) return false;
					else continue;
				}
				else if(!DFS(j,3-c)) return false;
			}
			else
			{
				if(col[j])
				{
					if(col[j]!=col[x]) return false;
					else continue;
				}
				else if(!DFS(j,c)) return false;
			}
		}
		return true;
	}
	bool pjiao(ppp x,ppp y)//�ж�������Բ�Ƿ��ཻ 
	{
		if(x.r>y.r) swap(x,y);
		if(y.l>x.r||y.l<x.l) return false;
		return true;
	}
	bool judge()//����֪ƥ�������£��ж��ܷ����Բ�Ϸ����� 
	{
		cnt=0;
		memset(pre,0,sizeof(pre));
		memset(col,0,sizeof(col));
		int i,j;
		for(i=1;i<=cn;i++)
		for(j=i+1;j<=cn;j++)
		if(pjiao(b[i],b[j]))
		ae(i,j,1),ae(j,i,1);
		for(i=1;i<=cn;i++)
		if(!col[i])
		if(!DFS(i,1))
		return false;
		return true;
	}
	bool dfs(int x)//dfs��Է��� 
	{
		while(x<=n&&a[x]!=-1) x++;
		if(x==n+1) return judge();
		int i;
		for(i=x+1;i<=n;i++)
		if(a[i]==-1)
		{
			cn++;
			a[x]=a[i]=cn;
			b[cn]=(ppp)
			{x,i};
			if(dfs(x+1)) return true;
			cn--;
			a[x]=a[i]=-1;
		}
		return false;
	}
	/*
	�Ϸ������������ڵ�һ������ 
	
	���������������ڵڶ������� 
	*/
	bool CHECK()//�����ǰ׺���ж���֪���ְ�Բ�������������Զ�������Ƿ�Ϸ� 
	{
		int i,j;
		for(i=1;i<=cn;i++)
		for(j=i+1;j<=cn;j++)
		if(d[i]==d[j]&&pjiao(b[i],b[j]))
		return false;
		cnt=0;
		memset(pre,0,sizeof(pre));
		memset(col,0,sizeof(col));
		for(i=1;i<=cn;i++)
		{
			if((b[i].r-b[i].l)&1)
			{
				ae(b[i].l,b[i].r-1,0);
				ae(b[i].r-1,b[i].l,0);
			}
			else
			{
				if(d[i]==1)
				{
					ae(b[i].l,b[i].r-1,0);
					ae(b[i].r-1,b[i].l,0);
				}
				else
				{
					ae(b[i].l,b[i].r-1,1);
					ae(b[i].r-1,b[i].l,1);
				}
			}
			if(d[i]==1)
			{
				ae(b[i].l-1,b[i].l,1);
				ae(b[i].l,b[i].l-1,1);
				ae(b[i].r-1,b[i].r,1);
				ae(b[i].r,b[i].r-1,1);
			}
			else
			{
				ae(b[i].l-1,b[i].l,0);
				ae(b[i].l,b[i].l-1,0);
				ae(b[i].r-1,b[i].r,0);
				ae(b[i].r,b[i].r-1,0);
			}
		}
		ae(0,n,0);
		ae(n,0,0);
		for(i=0;i<=n;i++)
		if(!col[i])
		if(!DFS(i,1))
		return false;
		return true;
	}
	bool dingxiang(int x)//��������֪��Բ���� 
	{
		if(x==cn+1) return CHECK();
		d[x]=1;
		if(dingxiang(x+1)) return true;
		d[x]=0;
		return dingxiang(x+1);
	} 
	string getPossibility(vector <int> labels)
	{
		n=labels.size();
		int i,j;
		int Free=0;
		for(i=0;i<n;i++)
		{
			if(labels[i]==-1) Free++;
			else
			{
				if(!fan[labels[i]])
				{
					cn++;
					fan[labels[i]]=cn;
				}
				b[fan[labels[i]]].update(i+1);//��ɢ�� 
			}
			a[i+1]=labels[i];
		}
		if(Free<=10)//δȷ���ĵ���٣�ֱ��ö����Է��� 
		{
			if(dfs(1)) YES;
			else NO;
		}
		else //ȷ���ĵ���٣�ö����Щ��Բ�ķ��� 
		{
			if(dingxiang(1)) YES;
			else NO;
		}
	}
};