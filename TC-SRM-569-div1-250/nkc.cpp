#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
struct TheDevice
{
	int minimumAdditional(vector <string> plates)
	{
		int n=plates.size(),m=plates[0].size();
		int i,j,ans=0;
		for(i=0;i<m;i++)//ÿλ�������� 
		{
			int t1=0,t0=0;
			for(j=0;j<n;j++)
			{
				if(plates[j][i]=='0') t0++;
				else t1++;
			}
			ans=max(ans,max(0,2-t1)+max(0,1-t0));//ȡ���ֵ 
		}
		return ans;
	}
};