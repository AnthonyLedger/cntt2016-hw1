#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL a[1000005],b[1000005];
int f=1,cnt[1000005];

void work(int p,int r){//��p^r 
	int m=1;for(int i=1;i<=r;++i)m*=p;
	memset(b,0,m<<3);
	memset(cnt,0,m<<3);
	for(int k=0;k<r*p;++k){ 
		LL t=LL(k)*k;int s=t%m;
		for(int i=t%p;i<m;i+=p){
			if(b[i])continue;
			int j=i-s;
			if(j<0)j+=m;
			if(j==0)cnt[i]=r;
			else while(j%p==0)++cnt[i],j/=p;//���м���p 
			if(cnt[i]>=r)b[i]=t+1;//p�ĸ������� 
		}
	}
	for(int i=0;i<m;++i)if(!b[i])b[i]=999999999999999ll;
	for(int i=f*m-1;i>=0;--i)a[i]=max(a[i%f],b[i%m]);//�ϲ��� 
	f*=m;
}

class SparseFactorial {
public:
	long long getCount(long long lo, long long hi, long long divisor) {
		int p=divisor;
		for(int i=2;i<=p;++i)
		if(p%i==0){
			int j=0;
			while(p%i==0)++j,p/=i;//�ֽ������� 
			work(i,j);
		}
		--lo;p=divisor;
		LL ret=0,j;
		for(int i=0;i<p;++i){
			j=a[i]/p*p+i;
			if(j<a[i])j+=p;//�����С�Ĵ��ڵ���a_i��mod p=i���� 
			if(j<=lo)ret-=(lo-j)/p+1;//��ȥ[1,L-1]��� 
			if(j<=hi)ret+=(hi-j)/p+1;//����[1,R]��� 
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
