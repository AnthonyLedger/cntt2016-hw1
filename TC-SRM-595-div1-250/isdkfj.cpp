#include <bits/stdc++.h>

using namespace std;

int f[1005],g[1005];

class LittleElephantAndIntervalsDiv1 {
public:
	long long getNumber(int M, vector <int> L, vector <int> R) {
		for(int i=0;i<L.size();++i)
			for(int j=L[i];j<=R[i];++j)f[j]=i+1;//���������Ĵξ��� 
		long long ret=1;
		for(int i=1;i<=M;++i)if(f[i]&&!g[f[i]])g[f[i]]=1,ret<<=1;//��һ�ξͳ�2 
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
