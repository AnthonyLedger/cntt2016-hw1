#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL n;
vector <string> ret;

void dfs(LL x,string y){
	if(x>n)return;
	if(ret.size()==50)return;//50������ 
	if(x)ret.push_back(y+".mp3"); 
	for(int i=!x;i<10;++i)dfs(x*10+i,y+char(i+48));//��С������ 
}

class FoxAndMp3 {
public:
	vector <string> playList(int n) {
		::n=n;
		dfs(0,"");//��0��ʼ���� 
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
