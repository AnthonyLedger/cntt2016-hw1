#include <bits/stdc++.h>

using namespace std;

int sg[1000005],res[1000005],cnt[1000005];
bool flag[100005];

class TheDivisionGame {
public:
	long long countWinningIntervals(int L, int R) {
		for(int i=0;i<=R-L;++i)res[i]=i+L;
		for(int i=2;i<=100000;++i)
		if(!flag[i]){
			for(int j=2*i;j<=100000;j+=i)flag[j]=1;//ɸ����100000������ 
			for(int j=L/i*i+(L%i>0)*i;j<=R;j+=i)//�ҳ�����[L,R]��i�ı��� 
			while(res[j-L]%i==0){
				++sg[j-L];
				res[j-L]/=i;
			}
		}
		for(int i=0;i<=R-L;++i)sg[i]+=(res[i]>1);//���д����� 
		cnt[0]=1;
		long long ret=1ll*(R-L+2)*(R-L+1)/2;
		for(int i=0,j=0;i<=R-L;++i){
			j^=sg[i];//ǰ׺��� 
			ret-=cnt[j];
			++cnt[j];
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
