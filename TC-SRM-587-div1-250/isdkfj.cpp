#include <bits/stdc++.h>

using namespace std;


class JumpFurther {
public:
	int furthest(int N, int badStep) {
		int ret=0;
		for(int i=1;i<=N;++i){
			ret+=i;//�� 
			if(ret==badStep)--ret;//������ 
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
