#include <bits/stdc++.h>

using namespace std;


class EelAndRabbit {
public:
	int getmax(vector <int> l, vector <int> t) {
		int n=l.size();
		vector<pair<int,int> >a;
		vector<int>b;
		for(int i=0;i<n;++i){
			int x=t[i],y=t[i]+l[i];//���ʲôʱ����ԭ�� 
			a.push_back(make_pair(x,y));
			b.push_back(x);
			b.push_back(y);
		}
		int ans=0;
		for(int i=0;i<b.size();++i)
			for(int j=0;j<b.size();++j){//��һ���ڶ˵�ȡ�� 
				int cnt=0;
				for(int k=0;k<a.size();++k)
				if((a[k].first<=b[i]&&b[i]<=a[k].second)||(a[k].first<=b[j]&&b[j]<=a[k].second))
					++cnt;//ͳ�Ƹ��� 
				ans=max(ans,cnt);
			}
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
