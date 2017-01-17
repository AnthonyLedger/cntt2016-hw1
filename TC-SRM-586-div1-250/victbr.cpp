#include <bits/stdc++.h>

using namespace std;

class PiecewiseLinearFunction{
	public:
		int n,ans;
		map <int,int> q;
		int maximumSolutions(vector<int> y){
			n = y.size();
			//��һ��������������֮һ��ȡ�� 
			for (int i = 1;i < n;i++){
				if (y[i] == y[i-1]) return -1;
				//�������ϲ�֣���mapά�� 
				if (y[i-1] < y[i]) {
					q[y[i-1]*2]++;
					q[  y[i]*2]--;
				}
				else{
					q[y[i]*2+1]++;
					q[y[i-1]*2+1]--;
				}
				if (i == n-1){
					q[y[i]*2]++;
					q[y[i]*2+1]--;
				}
			}
			int now = 0;
			for (map<int,int>::iterator it = q.begin();it != q.end();it++){
				now += it->second;
				ans = max(ans,now);
			}
			return ans;
		}
};
