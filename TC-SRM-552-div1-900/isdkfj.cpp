#include <bits/stdc++.h>

using namespace std;

int p[1000005],tot;
bool flag[1000005];

long long f(int x,long long n){//�ݹ���� 
	if(x>tot||p[x]>n)return 1;//��������������p>n
	if((long long)p[x]*p[x]>n)return upper_bound(p+1,p+tot+1,n)-p-x+1;//p^2>n
	long long ret=f(x+1,n),q=(long long)p[x]*p[x],t=p[x];
	for(;t<=n;t=t*q)ret+=f(x+1,n/t);//ö��ָ���ݹ���� 
	return ret;
}

class HolyNumbers {
public:
	long long count(long long upTo, int maximalPrime) {
		for(int i=2;i<=maximalPrime;++i){//ŷ��ɸ�������� 
			if(!flag[i])p[++tot]=i;
			for(int j=1,k;j<=tot&&(k=p[j]*i)<=maximalPrime;++j){
				flag[k]=1;
				if(i%p[j]==0)break;
			}
		}
		return f(1,upTo);
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
