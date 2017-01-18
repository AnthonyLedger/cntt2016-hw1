#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 2300
using namespace std;
struct Matrix
{
	double a[2][2];
	Matrix()
	{
		a[0][0]=a[1][1]=1;
		a[1][0]=a[0][1]=0;
	}
};
Matrix ret,st;
Matrix operator *(const Matrix &x,const Matrix &y)
{
	memset(ret.a,0,sizeof(ret.a));
	int i,j,k;
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	for(k=0;k<2;k++)
	ret.a[i][j]+=x.a[i][k]*y.a[k][j];
	return ret;
}
Matrix ksm(Matrix d,int c)
{
	Matrix ret=st;
	while(c)
	{
		if(c&1) ret=ret*d;
		d=d*d;c/=2;
	}
	return ret;
}
struct TheSwapsDivOne
{
	int a[N];
	double b[N];
	double find(vector <string> sequence, int k)
	{
		string S="";
		int i,j,tot=0;
		for(i=0;i<sequence.size();i++)
		S+=sequence[i];
		int n=S.size();
		//�������ε��������ڽ���һ���ٽ���һ�� 
		for(i=0;i<n;i++)
		a[i+1]=S[i]-48,tot+=a[i+1];
		Matrix di;
		di.a[0][0]=(double)(n-3)/(n-1);
		di.a[0][1]=0;
		di.a[1][0]=2.0*tot/(n*(n-1));
		di.a[1][1]=1;
		di=ksm(di,k);//����˷��������ʼ��ֵ���k�ν����������ֵ 
		for(i=1;i<=n;i++)
		b[i]=di.a[0][0]*a[i]+di.a[1][0];
		double ans=0;
		for(i=1;i<=n;i++)
		ans+=2.0*i*(n-i+1)/(n*(n+1))*b[i];//����ֵ���ϳ�������������еĸ��� 
		return ans;
	}
};