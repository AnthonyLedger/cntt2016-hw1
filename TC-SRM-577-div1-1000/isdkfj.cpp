#include <bits/stdc++.h>

using namespace std;

int fst[5555],nxt[555555],to[555555],w[555555],tt;
void ad(int x,int y,int z,int z2){//�ӱ� 
	nxt[++tt]=fst[x];fst[x]=tt;to[tt]=y;w[tt]=z;
	nxt[++tt]=fst[y];fst[y]=tt;to[tt]=x;w[tt]=z2;
}
int s,t,q[5555],d[5555],id[55][55];
bool bfs(){//���ͼ 
	int l=0,r=0;q[0]=s;
	memset(d,0,sizeof d);d[s]=1;
	while(l<=r){
		int x=q[l++];
		for(int i=fst[x];i;i=nxt[i])
		if(w[i]&&!d[to[i]])d[q[++r]=to[i]]=d[x]+1;
	}
	return d[t];
}
int cur[5555];//��ǰ���Ż� 
int dfs(int x,int a){//���� 
	if(x==t||a==0)return a;
	int flw=0,f;
	for(int&i=cur[x];i;i=nxt[i])
	if(d[to[i]]==d[x]+1&&(f=dfs(to[i],min(a,w[i])))){
		flw+=f;a-=f;
		w[i]-=f;w[i^1]+=f;
		if(a==0)break;
	}
	return flw;
}

class BoardPainting {
public:
	int minimalSteps(vector <string> target) {
		tt=1;
		int n=target.size(),m=target[0].size();
		int tot=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)if(target[i][j]=='#')
				id[i][j]=++tot;
		s=tot+1;t=tot+2;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)if(id[i][j]){
				int k=0;
				if(j==0||!id[i][j-1])++k;
				if(j==m-1||!id[i][j+1])++k;//ˮƽ��s���� 
				if(k)ad(s,id[i][j],k,0);
				k=0;
				if(i==0||!id[i-1][j])++k;
				if(i==n-1||!id[i+1][j])++k;//��ֱ��t���� 
				if(k)ad(id[i][j],t,k,0);
				if(i+1<n&&id[i+1][j])ad(id[i][j],id[i+1][j],1,1);
				if(j+1<m&&id[i][j+1])ad(id[i][j],id[i][j+1],1,1);//���ڵĵ����� 
			}
		int ans=0;
		while(bfs()){
			memcpy(cur,fst,sizeof fst);
			ans+=dfs(s,999999999);
		}
		return ans/2;//�߽��ĸ�������2 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
