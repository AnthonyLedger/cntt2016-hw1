#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class RobotHerb {
public:
	long long getdist(int T, vector <int> a) {
		LL x=0,y=0;int f=0;
		for(int k=0;k<4;++k)//ģ��4�� 
			for(int i=0;i<a.size();++i){
				if(f==0)x+=a[i];
				else if(f==1)y-=a[i];
				else if(f==2)x-=a[i];
				else if(f==3)y+=a[i];//�� 
				f=(f+a[i])%4;
			}
		x=x*(T/4);y=y*(T/4);//T/4�ζ���һ���� 
		for(int k=0;k<T%4;++k)//ģ��T%4�� 
			for(int i=0;i<a.size();++i){
				if(f==0)x+=a[i];
				else if(f==1)y-=a[i];
				else if(f==2)x-=a[i];
				else if(f==3)y+=a[i];//�� 
				f=(f+a[i])%4;
			}
		return abs(x)+abs(y);//�� 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
