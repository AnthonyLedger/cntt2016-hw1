#include <bits/stdc++.h>

using namespace std;

bitset<1000001>f;

class MayTheBestPetWin {
public:
	int calc(vector <int> A, vector <int> B) {
		int n=A.size(),sa=0,sb=0;
		f[0]=1;
		for(int i=0;i<n;++i)f|=f<<(A[i]+B[i]);//����������Щ�� 
		for(int i=0;i<n;++i)sa+=A[i],sb+=B[i];//A��B�ĺ� 
		int ret=998244353;
		for(int i=0;i<=1000000;++i)if(f[i])
			ret=min(ret,max(sb-i,i-sa));//����� 
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
