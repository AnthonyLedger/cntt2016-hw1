#include <bits/stdc++.h>

using namespace std;

int cnt[26];

class LittleElephantAndString {
public:
	int getNumber(string A, string B) {
		int n=A.size(),ret=n;
		for(int i=0;i<n;++i)++cnt[A[i]-'A'],--cnt[B[i]-'A'];
		for(int i=0;i<26;++i)if(cnt[i])return -1;//������ͬ 
		for(int i=n-1,j=n-1;i>=0;--i){
			while(j>=0&&A[j]!=B[i])--j;//����һ�������ĸ 
			if(j<0)break;
			--ret;--j;//�𰸼�1 
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
