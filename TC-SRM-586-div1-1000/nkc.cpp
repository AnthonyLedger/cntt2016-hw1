#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 27
using namespace std;
struct StringWeight
{
	int f[51][N][N];
	//f[i][j][k]��ʾǰi�����У�������j����ĸ����������k����ĸ���Ժ���Ҳ������֣� 
	int getMinimum(vector <int> L)
	{
		int n=L.size();
		int i,j,k,l,o,p;
		memset(f,0x3f,sizeof(f));
		f[0][0][0]=0;
		for(i=0;i<n;i++)
		for(j=0;j<=26;j++)
		for(k=0;k<=j;k++)
		{
			for(l=max(0,min(L[i],26)-(j-k));l+j<=26;l++)
			for(o=0;o+k<=j+l;o++)
			{
				//��ʾ�ڵ�i�������У���������l����ĸ���������o����ĸ �����а��������￪ʼ�������ս����ĸ 
				int tmp=0;
				p=min(j-k,o);
				tmp+=(1+p)*p/2;//������֮ǰ��ĳ�ο�ʼ������ν����Ĺ��� 
				if(j-k>o) tmp+=(j-k-o)*L[i];//�������˵������֮ǰĳ�ο�ʼ����֮��ĳ�ν������������ô���γ��ȶ���Ҫ������𰸣����ҿ�������������䲻�м乻�ĵط� 
				else if(L[i]>26) tmp+=L[i]-26;//�������˵��û������������򳤳���������Ҫ��ĳ�����ڵ���ĸ��� 
				p=min(l,j+l-k-o);
				tmp+=p*(p-1)/2;//�������ο�ʼ�Ĺ��ף���Ҫ�ٳ�����ο�ʼ����ν����ķ����� 
				f[i+1][j+l][k+o]=min(f[i+1][j+l][k+o],tmp+f[i][j][k]);
			}
		}
		int ans=707185547;
		for(i=0;i<=26;i++)
		ans=min(ans,f[n][i][i]);//i��ʾһ�����˶�������ĸ 
		return ans;
	} 
};