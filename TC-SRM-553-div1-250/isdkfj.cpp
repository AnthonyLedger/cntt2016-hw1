#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
struct info{
	int x; LL y;
	void operator+=(const info&rhs){
		x+=rhs.x;y+=rhs.y;
	}
}s[1005];

class Suminator {
public:
	int findMissing(vector <int> program, int wantedResult) {
		int tot=55,po=wantedResult;//����ջ��źܶ�0 
		for(int i=0;i<program.size();++i)
		if(program[i]==0){
			s[tot-1]+=s[tot];
			--tot;
		} else {
			++tot;
			if(program[i]==-1)s[tot].x=1,s[tot].y=0;
			else s[tot].x=0,s[tot].y=program[i];
		}//��-1��λ��Ϊx(x>0)���г����� 
		int ans;
		if(s[tot].x==0){//�ⷽ�� 
			if(s[tot].y==po)ans=1;
			else ans=-1;
		} else if(s[tot].y<=po-1)ans=po-s[tot].y;
		else ans=-1;
		tot=55;
		for(int i=0;i<=tot;++i)s[i].x=s[i].y=0;
		for(int i=0;i<program.size();++i)
		if(program[i]<=0){//�����Ǹ�λ��Ϊ0���Ƿ���� 
			s[tot-1]+=s[tot];
			--tot;
		} else {
			++tot;s[tot].x=0;
			s[tot].y=program[i];
		}
		if(s[tot].y==po)ans=0;//���´� 
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
