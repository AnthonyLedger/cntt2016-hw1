#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 51
using namespace std;
struct TheTree
{
	int maximumDiameter(vector <int> cnt)
	{
		int n=cnt.size();
		int i,j,t=n-1,ans=0;
		for(i=n-1;i>=-1;i--)//�������iΪ���Ĵ� 
		{
			ans=max(ans,n-1-i+t-i);//һ�浽�ף���һ�浽��һ��ֻ��һ���ĵ��Ϸ� 
			if(i!=-1&&cnt[i]==1) t=i-1;
		}
		return ans;
	}
};