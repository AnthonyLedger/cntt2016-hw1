#include <bits/stdc++.h>

using namespace std;

struct orz{
	int x,y,z;
	bool operator<(const orz&otz)const{
		return z<otz.z;
	}
}e[555555];
int fa[5555],n,m,tot;
int ge(int x){//���鼯 
	return x==fa[x]?x:fa[x]=ge(fa[x]);
}

class ArcadeManao {
public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		n=level.size();
		m=level[0].size();
		for(int i=1;i<=n*m;++i)fa[i]=i;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)if(level[i][j]=='X'){
				int x=i*m+j+1;
				for(int k=0;k<i;++k)if(level[k][j]=='X'){
					int y=k*m+j+1;
					++tot;
					e[tot].x=x;
					e[tot].y=y;
					e[tot].z=i-k;//�������� 
				}
				if(j+1<m&&level[i][j+1]=='X'){
					int t1=ge(x),t2=ge(x+1);
					if(t1!=t2)fa[t2]=t1;//ֱ�Ӻϲ� 
				}
			}
		int mb=(coinRow-1)*m+coinColumn,sb=n*m;
		if(ge(mb)==ge(sb))return 0;//�Ѿ���ͨ 
		sort(e+1,e+tot+1);
		for(int i=1;i<=tot;++i){//��С������ 
			int x=ge(e[i].x),y=ge(e[i].y);
			if(x!=y)fa[y]=x;
			if(ge(mb)==ge(sb))return e[i].z;
		}
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
