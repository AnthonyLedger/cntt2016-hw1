/*
	���ڴ�k������k����������ж��Ƿ���Ի�ԭ��
	���Ի�ԭ���ҽ�����ԭ�������ͬ�� 
	��Ȼ�𰸿��Զ��� 
*/ 
#include <bits/stdc++.h>

using namespace std;

const int N = 410;
 
class DrawingPointsDivOne{
	public:
		int n,f[N][N],g[N][N];
		int maxSteps(vector<int> x, vector<int> y){
			n = x.size();
			for (int i = 0;i < n;i++)
				x[i] += 71,y[i] += 71;
			/*
				������͹�����ʱ����������������
				�����͹����Ϊÿ��һ�ξ����һ����������139�κ�ͻ���͹��  
			*/ 
			int l = 0,r = 200,mid = (l+r+1) >> 1;
			while (l < r){
				if (check(mid,x,y)) l = mid;
				else r = mid-1;
				mid = (l+r+1)>>1;
			}
			if (l == 200) return -1;
			else return l;
		}
		bool check(int k,vector<int> x, vector<int> y){
			int cnt = 0;
			memset(f,0,sizeof(f));
			memset(g,0,sizeof(g));
			k++;
			/*
				k���������ÿ�����γ�һ��k*k�ĵ���k���������ʣ�µĵ㽫�ڴ���k�Ĳ���ʱ������
				Ϊ�˷��㴦��ֱ����k=k++ 
			*/
			/*
				��ά��� 
			*/
			for (int i = 0;i < n;i++){
				f[x[i]][y[i]]++;
				f[x[i]+k][y[i]+k]++;
				f[x[i]+k][y[i]]--;
				f[x[i]][y[i]+k]--;
			}
			for (int i = 1;i <= 400;i++)
				for (int j = 1;j <= 400;j++)
					f[i][j] += f[i-1][j]+f[i][j-1]-f[i-1][j-1];
			for (int i = 1;i <= 400;i++)
				for (int j = 1;j <= 400;j++)
					if (f[i][j] == 0) g[i][j] = 0;
					else{
						int m = min(min(g[i-1][j],g[i][j-1]),g[i-1][j-1]);
						g[i][j] = m+1;
						if (g[i][j] >= k) cnt++;
					}
			return cnt == n;
		}
};
