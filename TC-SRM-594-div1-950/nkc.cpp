#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans=4;
struct FoxAndAvatar
{
	void dfs(int step,int n,int w,int x)//���� 
	{
		if(step>=ans-1) return;
		if(w==1&&(x==1||x==n)) ans=step+1;
		if(n%w==1&&(x==n)) ans=step+1;
		if(x==w&&n<2*w) ans=step+1;
		if((x==1||x==n)&&n<=w) ans=step+1;
		//����һ����ɵ���� 
		if(step==2) return;//��Ϊ�����Ϊ4�����Բ������Ͳ������� 
		int h=(x-1)/w+1,l=(x-1)%w+1;
		dfs(step+1,min(h*w,n),w,x);//����ȫ���Ƴ� 
		int i,j;
		for(i=1;i<=w;i++)
		for(j=1;j<h;j++)
		dfs(step+1,n-i*j,w,x-i*j);//�Ƴ��Ϸ�ĳ������ 
		for(i=1;i<l;i++)
		for(j=1;j<=h;j++)
		{
			if(i<=(n-1)%w+1) dfs(step+1,n-((n-1)/w+1-(h-j))*i,w,x-j*i);
			else dfs(step+1,((n-1)/w)*w-((n-1)/w-(h-j))*i,w,x-i*j);
		}//�Ƴ�����һ�����׵ľ��� 
		for(i=l+1;i<=w;i++)
		for(j=1;j<h;j++)
		{
			if(i<=(n-1)%w+1) dfs(step+1,n-((n-1)/w+1-(h-1-j))*(i-l),w,x-j*(i-l));
			else dfs(step+1,((n-1)/w)*w+min(l,(n-1)%w+1)-((n-1)/w-(h-1-j))*(i-l),w,x-j*(i-l));
		}//�Ƴ�����һ�����׵ľ��� 
	}
	int minimalSteps(int n, int width, int x)
	{
		if(n==1) return 0;
		dfs(0,n,width,x);
		return ans;
	}
};