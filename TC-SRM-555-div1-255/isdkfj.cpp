#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
map<LL,bool>flag;//�Ƿ���5�Ĵ��� 
LL p[55][55];//i..j��ɵ��� 
int f[55];//ǰi�����ֳɼ��� 

class CuttingBitString {
public:
	int getmin(string S) {
		flag[1]=1;LL tmp=1;
		for(int i=1;i<=22;++i){
			tmp*=5;flag[tmp]=1;
		}
		if(S[0]=='0')return -1;
		f[0]=1;p[0][0]=1;
		for(int i=1;i<S.size();++i){
			f[i]=99999;
			p[i][i]=S[i]-48;
			for(int j=0;j<i;++j)if(p[j][i-1])p[j][i]=p[j][i-1]*2+S[i]-48;
			for(int j=0;j<i;++j)if(flag[p[j+1][i]])f[i]=min(f[i],f[j]+1);//ö�ٶϵ� 
			if(flag[p[0][i]])f[i]=1;//����һ�� 
		}
		if(f[S.size()-1]==99999)return -1;
		else return f[S.size()-1];
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
