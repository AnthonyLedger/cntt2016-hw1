#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define N 11
#define mp(x,y) make_pair(x,y)
using namespace std;
struct Mountains
{
	static const int mod=1e9+9;
	map<pair<int,string>,int>P;
	int n,W;
	int st[N],en[N],h[N];
	int dfs(int x,string S)
	{
		int i,j;
		if(P.find(mp(x,S))!=P.end()) return P[mp(x,S)];
		if(x==0) return 1;
		int ret=0;
		if(st[x]==-1)//����ɽ���ɼ���ֱ�Ӽ���� 
		{
			int cnt=0;
			for(i=0;i<W;i++)
			if(S[i]>=h[x]) cnt++;
			ret=(long long)cnt*dfs(x-1,S)%mod;
		}
		else
		{
			for(i=st[x];i<=en[x];i++)//ö������ɽ��λ�� 
			{
				bool can=true;
				if(h[x]-(i-st[x])<=S[st[x]]) can=false;
				if(h[x]-(en[x]-i)<=S[en[x]]) can=false;
				if(st[x]!=0&&h[x]-(i-(st[x]-1))>S[st[x]-1]) can=false;
				if(en[x]!=W-1&&h[x]-(en[x]+1-i)>S[en[x]+1]) can=false;
				if(!can) continue;//�ж��Ƿ�Ϸ� 
				string tmp=S;
				for(j=0;j<W;j++)
				tmp[j]=max(tmp[j],(char)(h[x]-abs(i-j)));
				(ret+=dfs(x-1,tmp))%=mod;//������һ�� 
			}
		}
		P[mp(x,S)]=ret;
		return ret;
	}
	int countPlacements(vector <int> heights, vector <string> visibility)
	{
		n=heights.size(),W=visibility[0].size();
		int i,j;
		for(i=0;i<n;i++)
		{
			h[i+1]=heights[i];
			st[i+1]=en[i+1]=-1;
			j=0;
			while(j<W&&visibility[i][j]=='-') j++;
			if(j==W) continue;
			st[i+1]=j;
			while(j<W&&visibility[i][j]=='X') j++;
			en[i+1]=j-1;
		}//��ͳ��ÿ��ɽ�Ŀɼ����� 
		string s="";
		int t=0;
		for(i=0;i<W;i++)
		s+=t;
		return dfs(n,s);//���仯���� 
	}
};