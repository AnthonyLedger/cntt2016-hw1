#include <bits/stdc++.h>

using namespace std;

int f[55][27][27];
void get(int&x,int y){if(x>y)x=y;}
int ss(int l,int r){//��������һ�εĺ� 
	if(l>r)return 0;
	return (l+r)*(r-l+1)/2;
}

class StringWeight {
public:
	int getMinimum(vector <int> L) {
		int n=L.size(),s=0;
		memset(f,0x3f,sizeof f);
		f[0][0][0]=0;
		for(int i=0;i<n;++i){//ǰi���� 
			int t=L[i],t2=min(t,26);
			for(int j=0;j<=26;++j)//j����ĸ 
				for(int k=0;k<=j;++k)//k������ 
					for(int l=max(t2-j+k,0);l+j<=26&&l<=t2;++l)//���õ���ĸ 
						for(int m=0;m<=j-k;++m)//�ɵ������ 
							for(int c=0;c<=l;++c)//�µ������ 
							if(m<j-k)get(f[i+1][l+j][m+c+k],f[i][j][k]+ss(s+1,s+m)-ss(s+t-(l-c)+1,s+t));
							else if(c<l)get(f[i+1][l+j][m+c+k],f[i][j][k]+ss(s+1,s+m)-ss(s+t-(l-c)+2,s+t)-(s+m+c+1));
							else get(f[i+1][l+j][m+c+k],f[i][j][k]+ss(s+1,s+m)+t-(m+c));
			s+=t;
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<=26;++i)ans=min(ans,f[n][i][i]);
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
