#include <bits/stdc++.h>

using namespace std;


class FoxPaintingBalls {
public:
	long long theMax(long long R, long long G, long long B, int N) {
		long long k=1ll*N*(N+1)/6;//ÿ����ɫ�м��� 
		if(N%3!=1)return min(min(R,G),B)/k;//ֱ����� 
		if(N==1)return R+G+B;//���� 
		long long ret=min(min(R,G),B)/k; 
		return min(ret,(R+G+B)/(3*k+1));//n%3=1����� 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
