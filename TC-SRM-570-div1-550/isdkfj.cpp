#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n,fst[55],to[105],nxt[105],tt;
LL f[55][55][55],g[55][55][55];//f:ȡx g:��ȡx 

int dfs(int x,int fa){
	f[x][1][1]=1;
	g[x][0][0]=1;//��ʼ�� 
	int siz=1; 
	for(int p=fst[x];p;p=nxt[p])
	if(to[p]!=fa){
		int ts=dfs(to[p],x);
		for(int i=siz;i>=0;--i)
			for(int j=i;j>=0;--j)
			if(f[x][i][j]||g[x][i][j])
				for(int k=ts;k>=0;--k)
					for(int l=k;l>=0;--l)
					if(k||l){
						if(f[to[p]][k][l]){
							f[x][i+k][j+l-1]+=f[x][i][j]*f[to[p]][k][l];//����һ�� 
							g[x][i+k][j+l]+=g[x][i][j]*f[to[p]][k][l];//��ȡto[p]���� 
						}
						if(g[to[p]][k][l]){
							f[x][i+k][j+l]+=f[x][i][j]*g[to[p]][k][l];//��ȡx���� 
							g[x][i+k][j+l]+=g[x][i][j]*g[to[p]][k][l];//��ȡx����
						}
					}
		siz+=ts;
	}
	return siz;
}

class CentaurCompany {
public:
	double getvalue(vector <int> a, vector <int> b) {
		n=a.size()+1;
		for(int i=0,x,y;i<a.size();++i){
			x=a[i];y=b[i];
			nxt[++tt]=fst[x];fst[x]=tt;to[tt]=y;
			nxt[++tt]=fst[y];fst[y]=tt;to[tt]=x;
		}
		dfs(1,-1);
		LL ans=0;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=i;++j)
			ans=(ans+(f[1][i][j]+g[1][i][j])*max(2*j-i-2,0));
			//i����j����ͨ��Ĵ�����max(2j-i-2,0)
		return 1.*ans/(1ll<<(n-1));
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
