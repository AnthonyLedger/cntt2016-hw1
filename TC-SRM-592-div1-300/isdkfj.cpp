#include <bits/stdc++.h>

using namespace std;


class LittleElephantAndBalls {
public:
	int getNumber(string S) {
		int ret=0;
		for(int i=0,a=0,b=0,c=0;i<S.size();++i){
			ret+=a+b+c;//��������֮�� 
			if(S[i]=='R'&&a<2)++a;
			if(S[i]=='G'&&b<2)++b;
			if(S[i]=='B'&&c<2)++c;//̰�ĵķ� 
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
