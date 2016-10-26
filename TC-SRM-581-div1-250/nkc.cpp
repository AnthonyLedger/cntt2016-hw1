#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct SurveillanceSystem
{
	string getContainerInfo(string containers, vector <int> reports, int L)
	{
		int n=containers.size(),m=reports.size();
		int i,j,k,x,y;
		int sum[51],ans[51]={0},totask[51]={0},tothav[51]={0};
		//sum[i]������iΪ��˵����ܿ������ٸ���Ʒ 
		//ans[i]����i��״̬��1Ϊ�ر���أ�2Ϊ���ܼ�� 
		for(i=0;i<=n-L;i++)//Ԥ����sum
		{
			sum[i]=0;
			for(j=0;j<L;j++)
			sum[i]+=(containers[i+j]=='X'?1:0);
			tothav[sum[i]]++;
		}
		for(i=0;i<m;i++)
		totask[reports[i]]++;
		//totask[i]�����ܿ���i����Ʒ������ͷ�ж��ٸ� 
		int tmp[51];
		for(i=0;i<=L;i++)
		{
			memset(tmp,0,sizeof(tmp));
			for(j=0;j<=n-L;j++)
			if(sum[j]==i)
			{
				for(k=0;k<L;k++)
				tmp[j+k]++;
			}
			//tmp[i]����iλ������Щ����������˶��ٴ� 
			for(j=0;j<n;j++)
			{
				if(tmp[j]>tothav[i]-totask[i]) ans[j]=1;
				else if(tmp[j]>0&&totask[i]>0&&!(ans[j]==1)) ans[j]=2;
			}
		}
		string ret;
		for(i=0;i<n;i++)
		{
			if(ans[i]==1) ret+='+';
			else if(ans[i]==2) ret+='?';
			else ret+='-';
		}
		return ret;
	}
};
/*int main()
{
	SurveillanceSystem P;
	vector<int> V;
	V.push_back(2);   
	cout<<P.getContainerInfo("-XXXXX-",V,3);
}*/