#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mo=1e9+7;
int f[55][2];

class DefectiveAddition {
public:
	int count(vector <int> cards, int n) {
		sort(cards.begin(),cards.end());
		int m=cards.size(),p=-1,t;
		for(int i=0;i<30;++i)if(cards[m-1]&(1<<i))p=i;//�����λ 
		if(p==-1)return n==0;//ȫ��0 
		t=1<<p;
		if(n>=t*2)return 0;
		f[0][0]=1;f[0][1]=0;//��ʼ�� 
		for(int i=0;i<m-1;++i)
			for(int j=0;j<2;++j){
				f[i+1][j]=LL(f[i][j])*min(cards[i]+1,t)%mo;//��ȡ���λ 
				if(cards[i]&t)
					f[i+1][j]=(f[i+1][j]+LL(f[i][j^1])*(cards[i]-t+1))%mo;//ȡ���λ 
			}
		int ret=f[m-1][n>>p];
		cards[m-1]^=t;//�ɵ����λ 
		return (ret+count(cards,n^t))%mo;//�ݹ� 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
