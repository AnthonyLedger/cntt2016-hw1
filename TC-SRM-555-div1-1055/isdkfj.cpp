#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
string goal,codes;
int n,L,R,tot,a[55],b[55];
LL p[55],ans;
LL get(LL t){//����1�ĸ��� 
	LL ret=1;
	for(;t;t>>=1)if(t&1)ret*=2;
	return ret;
}
void dfs(int x,LL t,int u){//ֱ��ö���ݳ� 
	if(x>tot){
		if(u){
			if(u&1)ans+=get(t);
			else ans-=get(t);
		}
		return;
	}
	dfs(x+1,t,u);
	dfs(x+1,t&p[x],u+1);
}

class MapGuessing {
public:
	long long countPatterns(string goal, vector <string> code) {
		n=goal.size();
		for(int i=0;i<code.size();++i)codes+=code[i];
		for(int i=0,x=0;i<codes.size();++i){//������������չ�ĳ��� 
			if(codes[i]=='<')--x;
			if(codes[i]=='>')++x;
			R=max(R,x);L=max(L,-x);
		}
		for(int i=L;i<n-R;++i){//ö����� 
			memset(a,-1,sizeof a);
			bool o=0;LL t=0;
			bool f=1;LL tmp=0;
			for(int k=0;k<n;++k)if(a[k]!=-1){//�ж��Ƿ��г�ͻ 
				if(a[k]!=goal[k]-48)f=0;
				else tmp|=1ll<<k;
			}
			if(f)o=1,t=tmp;
			for(int j=0,x=i;j<codes.size();++j){//ģ�� 
				if(codes[j]=='<')--x;
				if(codes[j]=='>')++x;
				if(codes[j]=='0')a[x]=0;
				if(codes[j]=='1')a[x]=1;
				bool f=1;LL tmp=0;
				for(int k=0;k<n;++k)if(a[k]!=-1){//�ж��Ƿ��г�ͻ 
					if(a[k]!=goal[k]-48)f=0;
					else tmp|=1ll<<k;
				}
				if(f)o=1,t=tmp;
			}
			if(o)p[++tot]=t;
		}
		if(L+R<=17){//���з�Χ���󣬽�����0�ĸ������� 
			for(int i=1;i<=tot;++i){
				int tu=0;
				for(int j=i+1;j<=tot;++j)
				if(p[j]&p[i])b[tu++]=j;
				for(int j=0;j<(1<<tu);++j){
					LL t=p[i];int u=1;
					for(int k=0;k<tu;++k)
					if(j&(1<<k))t&=p[b[k]],++u;
					if(u&1)ans+=get(t);
					else ans-=get(t);
				}
				if(tot-i-tu==0)continue;
				if(tu==0)--ans;
			}
		}else dfs(1,(1ll<<n)-1,0);//���з�Χ���ݳ�ĸ������� 
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
