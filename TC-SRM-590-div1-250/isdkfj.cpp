#include <bits/stdc++.h>

using namespace std;


class FoxAndChess {
public:
	string ableToMove(string begin, string target) {
		int n=begin.size(),i=0,j=0;
		for(;i<n;++i)
		if(begin[i]!='.'){//�ҵ�һ�� 
			while(j<n&&target[j]=='.')++j;
			if(j>=n)return "Impossible";//�Ҳ��� 
			if(begin[i]!=target[j])return "Impossible";//����ͬ 
			if(begin[i]=='L'&&j>i)return "Impossible";//���ұ� 
			if(begin[i]=='R'&&j<i)return "Impossible";//����� 
			++j;
		}
		while(j<n&&target[j]=='.')++j;
		if(j<n)return "Impossible";//�ж�� 
		return "Possible";
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
