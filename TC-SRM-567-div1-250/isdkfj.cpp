#include <bits/stdc++.h>

using namespace std;

int lo[100005],su[100005];
bool flag[100005];


class TheSquareRootDilemma {
public:
	int countPairs(int N, int M) {
		for(int i=1;i*i<=M;++i)su[i*i]=1;
		for(int i=1;i<=M;++i)su[i]+=su[i-1];//���[1,i]����ȫƽ�������� 
		for(int i=2;i<=N;++i)
		if(!flag[i])
			for(int j=i;j<=N;j+=i)
			if(!flag[j]){flag[j]=1;lo[j]=i;}//ɸ������С������ 
		int ret=su[M];
		for(int i=2;i<=N;++i){
			int x=i,y=1;
			while(x>1){
				if(x%(lo[x]*lo[x])==0)x/=lo[x]*lo[x];//����ƽ������ 
				else y*=lo[x],x/=lo[x];//����ƽ������ 
			}
			ret+=su[M/y];
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
