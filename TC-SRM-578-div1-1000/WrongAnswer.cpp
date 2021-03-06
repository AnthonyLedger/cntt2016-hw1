// FST:求最大权匹配（KM算法）数组忘记清空
#include <vector>
#include <cstring>
#define INF 2147483647
using namespace std;
class Match{
public:
	int nx,ny,w[60][60],lx[60],ly[60],slack[60],to[60];
	bool visx[60],visy[60];
	bool dfs(int i){
		visx[i]=1;
		for(int j=0,d;j<ny;j++)if(!visy[j]){
			if(d=lx[i]+ly[j]-w[i][j])slack[j]>d?slack[j]=d:1;
			else{
				visy[j]=1;
				if(to[j]==-1||dfs(to[j]))return to[j]=i,1;
			}
		}
		return 0;
	}
	int match(){
		if(nx>ny){
			for(int i=0;i<nx;i++)
				for(int j=0;j<ny&&j<i;j++)swap(w[i][j],w[j][i]);
			swap(nx,ny);
		}
		for(int i=0;i<nx;i++)
			for(int j=0;j<ny;j++)if(w[i][j]>lx[i])lx[i]=w[i][j];
		for(int i=0;i<ny;i++)to[i]=-1,ly[i]=0;
		for(int i=0;i<nx;i++){
			for(int j=0;j<ny;j++)slack[j]=INF;
			for(int d;d=INF;){
				for(int j=0;j<ny;j++)visx[j]=visy[j]=0;
				if(dfs(i))break;
				for(int j=0;j<ny;j++)!visy[j]&&d>slack[j]?d=slack[j]:1;
				for(int j=0;j<nx;j++)visx[j]?lx[j]-=d:1;
				for(int j=0;j<ny;j++)visy[j]?ly[j]+=d:slack[j]-=d;
			}
		}
		int s=0;
		for(int i=0;i<ny;i++)if(to[i]!=-1)s+=w[to[i]][i];
		return s;
	}
}solver;
class DeerInZooDivOne{
public:
	int N,pre[60],pos[60],now;
	struct edge{int to;bool del;edge*rev,*next;}E[110],*ne,*first[60],*fe[60];
	void link(int a,int b){
		*ne=(edge){b,0,ne+1,first[a]};first[a]=ne++;
		*ne=(edge){a,0,ne-1,first[b]};first[b]=ne++;
	}
	void dfs(int i,int f){
		pre[i]=now++;
		for(edge*e=first[i];e;e=e->next)if(e->to!=f)fe[e->to]=e,dfs(e->to,i);
		pos[i]=now;
	}
	int f[60][110];
	void calc(int i,int j){
		if(f[i][j])return;
		f[i][j]=1;
		for(edge*ei=first[i];ei;ei=ei->next)if(!ei->del&&ei!=fe[i]->rev)
			for(edge*ej=first[E[j].to];ej;ej=ej->next)if(!ej->del&&ej!=E[j].rev)calc(ei->to,ej-E);
		solver.nx=0;
		for(edge*ei=first[i];ei;ei=ei->next)if(!ei->del&&ei!=fe[i]->rev){
			solver.ny=0;
			for(edge*ej=first[E[j].to];ej;ej=ej->next)if(!ej->del&&ej!=E[j].rev)solver.w[solver.nx][solver.ny++]=f[ei->to][ej-E];
			solver.nx++;
		}
		f[i][j]+=solver.match();
	}
	int getmax(vector <int> a, vector <int> b){
		N=a.size()+1;ne=E;
		for(int i=0;i<N-1;i++)link(a[i],b[i]);
		now=0;dfs(0,-1);
		int ans=0,tmp;
		for(int i=1;i<N;i++){
			fe[i]->del=fe[i]->rev->del=1;
			memset(f,0,sizeof(f));
			for(int j=0;j<N;j++)if(pre[j]<pre[i]||pre[j]>=pos[i]){
				for(edge*ei=first[i];ei;ei=ei->next)if(!ei->del)
					for(edge*ej=first[j];ej;ej=ej->next)if(!ej->del)calc(ei->to,ej-E);
				solver.nx=0;
				for(edge*ei=first[i];ei;ei=ei->next)if(!ei->del){
					solver.ny=0;
					for(edge*ej=first[j];ej;ej=ej->next)if(!ej->del)solver.w[solver.nx][solver.ny++]=f[ei->to][ej-E];
					solver.nx++;
				}
				if((tmp=1+solver.match())>ans)ans=tmp;
			}
			fe[i]->del=fe[i]->rev->del=0;
		}
		return ans;
	}
};
