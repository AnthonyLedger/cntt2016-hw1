#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mo=1000000007;
int f[51][51][2501];

class LittleElephantAndPermutationDiv1 {
public:
	int getNumber(int N, int K) {
		f[0][0][0]=1;
		for(int i=0;i<N;++i)
			for(int j=0;j<=i+1;++j)
				for(int k=0;k<=K;++k)
				if(f[i][j][k]){
					LL t=f[i][j][k];
					f[i+1][j][min(k+i+1,K)]=(f[i+1][j][min(k+i+1,K)]+t*(2*j+1))%mo;
					//i+1�Լ��ã�i+1����ǰ����i+1��λ���Ȳ��i+1�Ȳ�����i+1��λ����ǰ�油�� 
					if(j)f[i+1][j-1][min(k+2*i+2,K)]=(f[i+1][j-1][min(k+2*i+2,K)]+t*j*j)%mo;
					//i+1����ǰ����i+1��λ����ǰ�油�� 
					if((f[i+1][j+1][k]+=t)>=mo)f[i+1][j+1][k]-=mo;
					//i+1�Ȳ�����i+1��λ���Ȳ��� 
				}
		LL ans=f[N][0][K];
		for(int i=1;i<=N;++i)ans=ans*i%mo;//���Խ׳� 
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
