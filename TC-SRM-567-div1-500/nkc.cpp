#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct StringGame
{
	int tot[51][27];
	bool used[27],kick[51];
	vector <int> getWinningStrings(vector <string> S)
	{
		vector<int>ans;
		int n=S.size();
		int i,j,k;
		for(i=0;i<n;i++)
		for(j=0;j<S[i].size();j++)
		tot[i][S[i][j]-96]++; //ͳ��ÿ���ַ����� 
		for(i=0;i<n;i++)//ö������ѡ��Ĵ� 
		{
			bool f=true;
			int res=n,rea=26;
			memset(used,0,sizeof(used));
			memset(kick,0,sizeof(kick));
			while(res>1&&rea>0)
			{
				for(j=1;j<=26;j++)//��ѡ���ʵ��ַ� 
				if(!used[j])
				{
					bool can=true;
					for(k=0;k<n;k++)
					if(k!=i&&!kick[k]&&tot[k][j]>tot[i][j])
					can=false;
					if(can) break;
				}
				if(j==27) 
				{f=false;break;}
				used[j]=true;
				rea--;
				for(k=0;k<n;k++)
				if(tot[k][j]<tot[i][j]&&!kick[k]) 
				{kick[k]=true;res--;}
			}
			if(rea==0&&res!=1) f=false;//�����Ȼ��ƽ�� 
			if(f) ans.push_back(i);//ͳ�ƴ� 
		}
		return ans;
	}
};