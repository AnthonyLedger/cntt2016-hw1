#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL f[55][105];

class MonstersValley {
public:
	int minimumPrice(vector<long long> dread, vector <int> price) {
		int n=dread.size();
		f[0][price[0]]=dread[0];//��ʼ�� 
		for(int i=0;i<n-1;++i)
			for(int j=1;j<=2*(i+1);++j)
			if(f[i][j]){//ǰi����jԪ 
				f[i+1][j+price[i+1]]=max(f[i+1][j+price[i+1]],f[i][j]+dread[i+1]);//ֱ���� 
				if(f[i][j]>=dread[i+1])f[i+1][j]=max(f[i+1][j],f[i][j]);//���� 
			}
		int ret=0;
		for(int i=1;i<=2*n;++i)if(f[n-1][i]){ret=i;break;}//����С�� 
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
