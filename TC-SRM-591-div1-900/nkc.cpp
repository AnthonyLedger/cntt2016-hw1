#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct StringPath
{
	long long f[8][8][256][256];
	static const int mod=1e9+9;
	int ers(int k,int i)//ǿ�ƽ�k�ĵ�iλ��Ϊ0 
	{
		if(k&(1<<i)) k-=(1<<i);
		return k;
	}
	int sam(int k,int i)//��k�ĵ�iλ��Ϊ->��iλ�͵�i-1λ���л������ֵ 
	{
		if((k&(1<<(i-1)))&&!(k&(1<<i))) k+=(1<<i);
		return k;
	}
	int countBoards(int n, int m, string A, string B)
	{
		if(A[0]!=B[0]) return 0; 
		f[0][0][1][1]=1;
		int i,j,k,l;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)//ɨ������ 
		{
			if(i==n-1&&j==m-1) break;
			for(k=0;k<(1<<m);k++)
			for(l=0;l<(1<<m);l++)
			{
				f[i][j][k][l]%=mod;
				if(j==m-1)//�ж��Ƿ��¿�һ�� 
				{
					if(A[i+1]==B[i+1])//ͬһ���ַ����� 
					{
						f[i+1][0][k][l]+=f[i][j][k][l];//�������ַ� 
						f[i+1][0][ers(k,0)][ers(l,0)]+=f[i][j][k][l]*25;//��������ַ� 
					}
					else
					{
						f[i+1][0][k][ers(l,0)]+=f[i][j][k][l];
						f[i+1][0][ers(k,0)][l]+=f[i][j][k][l];
						f[i+1][0][ers(k,0)][ers(l,0)]+=f[i][j][k][l]*24;
					}
				}
				else//����ͬ�� 
				{
					if(A[i+j+1]==B[i+j+1])
					{
						f[i][j+1][sam(k,j+1)][sam(l,j+1)]+=f[i][j][k][l];
						f[i][j+1][ers(k,j+1)][ers(l,j+1)]+=f[i][j][k][l]*25;
					}
					else
					{
						f[i][j+1][sam(k,j+1)][ers(l,j+1)]+=f[i][j][k][l];
						f[i][j+1][ers(k,j+1)][sam(l,j+1)]+=f[i][j][k][l];
						f[i][j+1][ers(k,j+1)][ers(l,j+1)]+=f[i][j][k][l]*24;
					}
				}
			}
		}
		long long ans=0;//�������ǿ�����λΪ1 
		for(k=0;k<(1<<(m-1));k++)
		for(l=0;l<(1<<(m-1));l++)
		(ans+=f[n-1][m-1][k+(1<<(m-1))][l+(1<<(m-1))])%=mod;
		return ans;
	} 
};