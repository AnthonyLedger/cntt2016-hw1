#include <bits/stdc++.h>

using namespace std;

int mp[55],oc[55];

class NextAndPrev {
public:
	int getMinimum(int nextCost, int prevCost, string start, string goal) {
		if(start==goal)return 0;//������� 
		memset(mp,-1,sizeof mp);
		for(int i=0;i<start.size();++i){
			int x=start[i]-'a',y=goal[i]-'a';
			if(mp[x]!=-1&&mp[x]!=y)return -1;//ͬһ����ĸ��Ӧ�Ĳ�һ�� 
			mp[x]=y;oc[y]=1;
		}
		bool all=1;
		for(int i=0;i<26;++i)if(!oc[i])all=0;//�Ƿ�ȫ������ 
		if(all)return -1;
		vector<pair<int,int> >a;
		for(int i=0;i<26;++i)if(mp[i]!=-1)a.push_back(make_pair(i,mp[i]));
		int m=a.size(),ans=2147483647;
		for(int zz=0;zz<m;++zz){
			bool flag=1;
			for(int i=0;i<m-1;++i)if(a[i].second>a[i+1].second)flag=0;//�Ƿ��н��� 
			if(flag){
				for(int py=-1;py<=2;++py){//ƫ�Ƶ��� 
					for(int i=0;i<m;++i)a[i].second+=py*26;
					int tmp=0;
					for(int i=0;i<m;){
						int j=i,l=a[i].first,r=a[i].first;
						while(j<m&&a[j].second==a[i].second)r=a[j++].first;//��һ��Ŀ����ͬ�� 
						if(l<a[i].second)tmp+=nextCost*(a[i].second-l);//�������м��� 
						if(a[i].second<r)tmp+=prevCost*(r-a[i].second);//������� 
						i=j;
					}
					if(tmp<ans)ans=tmp;
					for(int i=0;i<m;++i)a[i].second-=py*26;
				}
			}
			a[0].first+=26;
			rotate(a.begin(),a.begin()+1,a.end());//ͷ�Ƶ�β 
		}
		if(ans==2147483647)return -1;
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
