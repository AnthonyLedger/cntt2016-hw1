#include <bits/stdc++.h>

using namespace std;

int f[55][55];

class GUMIAndSongsDiv1 {
public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		int n=tone.size();
		vector<pair<int,int> >v;
		for(int i=0;i<n;++i)v.push_back(make_pair(tone[i],duration[i]));
		sort(v.begin(),v.end());//���� 
		memset(f,0x3f,sizeof f);//��ʼ�� 
		for(int i=0;i<n;++i){
			f[i][1]=v[i].second;
			for(int j=2;j<=i+1;++j)//�ܹ�j�� 
				for(int k=0;k<i;++k)//��һ�� 
				f[i][j]=min(f[i][j],f[k][j-1]+v[i].first-v[k].first+v[i].second);
		}
		int ans=0;
		while(ans<=n){
			int mi=2147483647;
			for(int i=0;i<n;++i)mi=min(mi,f[i][ans+1]);//��Сֵ 
			if(mi<=T)++ans;//���´� 
			else break;
		}
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
