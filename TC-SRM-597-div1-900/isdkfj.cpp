#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mo=1000000007;
int fa[1000005],rf[1000005];
int ksm(LL x,int k){//������ 
	LL ret=1;
	for(;k;k>>=1,x=x*x%mo)if(k&1)ret=ret*x%mo;
	return ret;
}
LL z(int x,int y){//����� 
	if(y<0||y>x)return 0;
	return (LL)fa[x]*rf[y]%mo*rf[x-y]%mo;
}

class LittleElephantAndBoard {
public:
	int getNumber(int M, int R, int G, int B) {
		fa[0]=1;
		for(int i=1;i<=1000000;++i)fa[i]=(LL)fa[i-1]*i%mo;
		rf[1000000]=ksm(fa[1000000],mo-2);
		for(int i=999999;i>=0;--i)rf[i]=(LL)rf[i+1]*(i+1)%mo;//�׳˸��׳˵���Ԫ 
		int a=M-G,b=M-B,c=M-R;//�ⷽ�� 
		if(a<b)swap(a,b);
		if(a<c)swap(a,c);
		if(b<c)swap(b,c);
		int ans=0;
		for(int i=0;i<=b;++i){//�Ȱ�b����i������ 
			LL t=z(a-1,i)*z(i+i,c-b-a+1+i+i)
				+z(a,i)*z(i+i,c-b-a+i+i)*2
				+z(a+1,i)*z(i+i,c-b-a+i+i-1);//����������ò�շ���� 
				//�Ѷ������c����i���յ����� 
			ans=(ans+t%mo*z(b-1,i-1))%mo;//�������b����ȥ 
		}
		return ans*2%mo;//��һ�������ַ��� 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
