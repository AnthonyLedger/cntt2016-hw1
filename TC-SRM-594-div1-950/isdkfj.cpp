#include <bits/stdc++.h>

using namespace std;

int w;

bool check(int n,int x){//�ж��ܷ�һ�θ㶨 
	if(n<=w&&(x==1||x==n))return 1;//ֻ�в���һ�ж���x��ͷβ 
	if(w==1&&(x==1||x==n))return 1;//ֻ��һ�ж���x��ͷβ 
	if(x==n&&n%w==1)return 1;//���һ��ǡ�ö�һ��x 
	if(n<2*w&&x==w)return 1;//���һ��ֻ��x 
	return 0;
}

int dfs(int n,int x,int s){
	if(check(n,x))return 1;
	if(s==2)return 2;//��֦�������Ĵ� 
	int ret=998244353,u=(x-1)/w;
	for(int i=1;i<=u;++i)
		for(int j=1;j<=w;++j)
		ret=min(ret,dfs(n-i*j,x-i*j,s+1));//ɾ������ 
	int d=(n-1)/w,l=(x-1)%w,r=w-l-1,ll=(n-1)%w+1;
	for(int i=1;i<=u+1;++i)
		for(int j=1;j<=l;++j){
			int tmp=i*j;
			if(j<=ll)tmp+=(d-u)*j;
			else tmp+=(d-u-1)*j+ll;//Ϊ��ɾ�Ķྡ������ 
			ret=min(ret,dfs(n-tmp,x-i*j,s+1));//ɾ����� 
		}
	for(int i=1;i<=u+1;++i)
		for(int j=1;j<=r;++j){
			int tmp=i*j,res=ll-l-1;
			if(res<0)res=0;
			if(j<=res)tmp+=(d-u)*j;
			else tmp+=(d-u-1)*j+res;//Ϊ��ɾ�Ķྡ������ 
			ret=min(ret,dfs(n-tmp,x-(i-1)*j,s+1));//ɾ���ұ� 
		}
	if(d!=u)ret=min(ret,dfs((u+1)*w,x,s+1));//ɾ������ 
	return ret+1;
}

class FoxAndAvatar {
public:
	int minimalSteps(int n, int width, int x) {
		w=width;
		if(n==1)return 0;//���� 
		return min(4,dfs(n,x,0));
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
