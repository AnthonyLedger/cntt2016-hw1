#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 51
using namespace std;
struct XorCards
{
	int jd[N][N],b[N];
	bool hav[N];
	int a[N],A,n;
	int add()//���Ի��󷽳̵Ľ��� 
	{
		int i,j,k;
		for(i=n-1;i>=0;i--)
		if(a[i])
		{
			if(!hav[i])
			{
				hav[i]=true;
				for(j=i;j>=0;j--)
				jd[i][j]=a[j];
				b[i]=A;
				return i;
			}
			else
			{
				for(j=i;j>=0;j--)
				a[j]^=jd[i][j];
				A^=b[i];
			}
		}
		if(A==1) return -1;//ì�ܷ���-1 
		return 707;//û�гɹ����룬����707 
	}
	void back(int x)//ɾ��һ������ 
	{
		memset(jd[x],0,sizeof(jd[x]));
		b[x]=0;
		hav[x]=false;
	}
	long long numberOfWays(vector<long long> number, long long limit)
	{
		n=number.size();
		int i,j;
		long long ans=0,re=n;
		for(i=50;i>=0;i--)//��λ���Ӹߵ��ͼ��������ʱ�临�Ӷȱ�Ϊn^2logINF 
		{
			memset(a,0,sizeof(a));
			for(j=n-1;j>=0;j--)
			if(number[j]&(1LL<<i)) a[j]=1;
			A=!!(limit&(1LL<<i));
			if(!A)
			{
				j=add();
				if(j==-1) return ans;
				if(j!=707) re--;
			}
			else
			{
				A=0;
				j=add();//���������λ��ʼ��ͬ��С��m�� 
				if(j!=-1)
				{
					if(j!=707)
					{
						re--;
						ans+=(1LL<<re);
						re++;
						back(j);
					}
					else ans+=(1LL<<re);
				}
				//Ȼ�������������Ի� 
				memset(a,0,sizeof(a));
				for(j=n-1;j>=0;j--)
				if(number[j]&(1LL<<i)) a[j]=1;
				A=1;
				j=add();
				if(j==-1) return ans;
				if(j!=707) re--;
			}
		}
		ans+=(1LL<<re);
		return ans;
	}
};