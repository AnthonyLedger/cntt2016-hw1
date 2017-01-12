#include <bits/stdc++.h>

using namespace std;


class XorTravelingSalesman {
public:
	int maxProfit(vector <int> cityValues, vector <string> roads) {
		int n=cityValues.size();
		queue<pair<int,int> >q;
		static bool f[55][1024];//��i����j�ܷ񵽴� 
		f[0][cityValues[0]]=1;q.push(make_pair(0,cityValues[0]));//��ʼ�� 
		int ans=cityValues[0];
		while(!q.empty()){
			pair<int,int> x=q.front();q.pop();
			for(int i=0,t;i<n;++i){
				t=x.second^cityValues[i];
				if(roads[x.first][i]=='Y'&&!f[i][t]){//���֮ǰû�о͸��� 
					f[i][t]=1;
					q.push(make_pair(i,t));
					ans=max(ans,t);//���´� 
				}
			}
		}
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
