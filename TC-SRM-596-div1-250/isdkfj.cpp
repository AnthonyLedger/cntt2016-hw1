#include <bits/stdc++.h>

using namespace std;


class IncrementAndDoubling {
public:
	int getMin(vector <int> desiredArray) {
		int ret=0,mx=0;
		for(int i=0;i<desiredArray.size();++i){
			int x=desiredArray[i],cnt=0,flag=0;
			while(x){
				ret+=x&1;//1�ĸ��� 
				x>>=1;
				if(flag)++cnt;//����2�Ĳ������� 
				else flag=1;
			}
			mx=max(mx,cnt);
		}
		return ret+mx;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
