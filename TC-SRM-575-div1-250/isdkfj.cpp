#include <bits/stdc++.h>

using namespace std;


class TheNumberGameDivOne {
public:
	string find(long long n) {
		if(n&1)return "Brus";//�������ֱذ� 
		long long i=2;
		for(;i<n;i*=4);//2^(2k+1)���ֱذ� 
		if(i==n)return "Brus";
		return "John";
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
