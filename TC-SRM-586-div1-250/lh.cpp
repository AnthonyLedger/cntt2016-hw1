#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

/*
�����е�Yֵ��ɢ����ȡֵ��ͬ�ĵط�ֻ���ڹؼ���������ؼ���֮����֡� 
*/

class PiecewiseLinearFunction{
	private:
		static const int maxn=55;
		int use[maxn],n;
		vector<int> tt;
		
		int judge(double y){
//			printf("judge(%lf)\n",y);
			int ret=0;
			if (y==tt[0]) ++ret;
			for (int i=1;i<n;++i){
				if (y==tt[i]) ++ret;
				else if ((y-tt[i])*(y-tt[i-1])<0) ++ret;
			}
			return ret;
		}
	
	public:
		int maximumSolutions(vector <int> Y){
			n=Y.size();
			tt=Y;
			for (int i=0;i<n;++i) use[i]=Y[i];
			for (int i=1;i<n;++i) if (Y[i]==Y[i-1]) return -1;
			sort(use,use+n); 
			int top=unique(use,use+n)-use,ans=0;
			for (int i=0;i<top;++i){
				ans=max(ans,judge(use[i]));
				if (i!=0) ans=max(ans,judge((use[i]+use[i-1])*0.5));
			}
			return ans;
		}
};
