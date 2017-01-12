#include <bits/stdc++.h>

using namespace std;

const int inf=0x3f3f3f3f;
int col[99],n,L,R,top[99],ans,f[1<<6],S,T,du[99],ss,tt,tot,sum;
int fst[99],nxt[999],to[999],w[999],d[99],q[99];
vector<int> cc[9];
bool used[9],g[9][9];

void ad(int x,int y,int z){//���һ����x��y������Ϊz�ı� 
	nxt[++tot]=fst[x];fst[x]=tot;to[tot]=y;w[tot]=z;
	nxt[++tot]=fst[y];fst[y]=tot;to[tot]=x;w[tot]=0;
}
bool bfs(){//�����ssΪ���Ĳ��ͼ 
	memset(d,0,sizeof d);d[ss]=1;//��ʼ�� 
	int l=0,r=0;q[0]=ss;
	while(l<=r){//bfs
		int x=q[l++];
		for(int i=fst[x];i;i=nxt[i])
		if(!d[to[i]]&&w[i])
			d[q[++r]=to[i]]=d[x]+1;
	}
	return d[tt];
}
int dfs(int x,int a){//Ѱ������· 
	if(x==tt||a==0)return a;//���յ㷵�� 
	int rw=0,f;
	for(int i=fst[x];i;i=nxt[i])
	if(d[to[i]]==d[x]+1&&(f=dfs(to[i],min(a,w[i])))){//�ز��ͼ���� 
		rw+=f; a-=f;
		w[i]-=f; w[i^1]+=f;//�޸����� 
		if(a==0)break;//�Ż� 
	}
	return rw;
}
bool chk(){
	int db=n+n+1;//�ذ� 
	S=db+1;T=S+1;
	memset(fst,0,sizeof fst);tot=1;
	for(int i=1;i<=n;++i)ad(S,i,col[i]);
	for(int i=1;i<=n;++i)ad(i+n,T,col[i]);
	ad(db,T,inf);
	for(int i=0;i<cc[0].size();++i)ad(cc[0][i],db,inf);//��ذ����� 
	int ret=0;
	memset(du,0,sizeof du);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		if(g[i][j])ad(i,j+n,inf),++du[j+n],--du[i],++ret;
	ss=T+1;tt=ss+1;
	for(int i=1;i<=2*n;++i){
		if(du[i]>0)ad(ss,i,du[i]);//du>0��ss 
		if(du[i]<0)ad(i,tt,-du[i]);//du<0��tt 
	}//���½������� 
	ad(T,S,inf);
	int rr=0;
	while(bfs())rr+=dfs(ss,inf);
	if(rr!=ret)return 0;
	fst[ss]=fst[tt]=0;
	ss=S,tt=T;
	ret=0;
	while(bfs())ret+=dfs(ss,inf);
	return ret==sum;
}
int dp(){
	memset(f,0,sizeof f);
	f[(1<<n)-1]=1;
	for(int s=(1<<n)-2;s>=0;--s)//dp 
		for(int i=1;i<=n;++i)
		if((s&(1<<(i-1)))==0&&(s&top[i])==top[i])f[s]+=f[s|(1<<(i-1))];
	return f[0];
}
void splay(int le,int x,int p){//����һ��ͼ 
	if(x==n){
		if(chk()){//�ж��Ƿ���� 
			int get=dp();//�󷽰��� 
			ans+=L<=get&&get<=R;//�ۼ� 
		}
		return;
	}
	for(int i=p+1;i<=n;++i)//������һ���� 
	if(!used[i]){
		used[i]=1;
		cc[le].push_back(i);
		if(le){
			for(int s=1;s<1<<cc[le-1].size();++s){//ö����˭���� 
				for(int j=0;j<cc[le-1].size();++j)
				if(s&(1<<j)){
					top[cc[le-1][j]]|=1<<(i-1);
					g[i][cc[le-1][j]]=1;
				}
				splay(le,x+1,i);
				if(x<n-1)splay(le+1,x+1,0);//�������� 
				for(int j=0;j<cc[le-1].size();++j)
				if(s&(1<<j)){
					top[cc[le-1][j]]^=1<<(i-1);
					g[i][cc[le-1][j]]=0;
				}
			}
		} else {
			splay(le,x+1,i);
			if(x<n-1)splay(le+1,x+1,0);//�������� 
		}
		cc[le].pop_back();
		used[i]=0;
	}
}

class CosmicBlocks {
public:
	int getNumOrders(vector <int> blockTypes, int minWays, int maxWays) {
		n=blockTypes.size();
		for(int i=0;i<n;++i)col[i+1]=blockTypes[i],sum+=col[i+1];
		L=minWays; R=maxWays;
		splay(0,0,0);
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
