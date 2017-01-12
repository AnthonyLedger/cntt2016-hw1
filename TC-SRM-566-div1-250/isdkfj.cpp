#include <bits/stdc++.h>

using namespace std;

bool g[55][55];

class PenguinSledding {
public:
	long long countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2) {
		int n=numCheckpoints;
		for(int i=0,x,y;i<checkpoint1.size();++i){
			x=checkpoint1[i];
			y=checkpoint2[i];
			g[x][y]=g[y][x]=1;//��ͼ 
		}
		long long ret=0;
		for(int i=1;i<=n;++i){//ö���м�ĵ� 
			int t1=0,t2=0;
			for(int j=1;j<=n;++j)
			if(g[i][j])++t1,t2+=j<i;//���� 
			ret+=(1ll<<t1)-1-t1+t2;//���͵ĸ��� 
		}
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
				ret+=g[i][j]&&g[j][k]&&g[k][i];//��Ԫ�� 
		return ret+1;//ȫ��ѡ 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
