/*
	����ÿһ�������������������1.��ֵ�ڶ��� 2.��ֵ�ڶ˵� 
	����ö��ÿ������ȡ��ֵ��������ж��Ƿ�Ϸ����ɡ�
	ֱ�������n^3�ģ�ע�⵽��
	�������xixj��Ŀ�꺯��������һ����Ȼ��һ��(xi��xj)�ڶ˵�ȡ��ֵ�����Բ����ڡ�
	��ʱԭʽ�ɿ���xixj+bixi+bjxj+c=(xi+bj)(xj+bi)-c'����Ȼ��xi+bj=xj+biʱȡ��ֵ��
	����xi-xj=bi-bj�����ڶ���������ֵ�ڶ����k��xixk�����ڡ�����bi-bjֻ����ֵ�ڶ˵��k�йء�
	���ǿ���On��xi-xj������On^2��⡣ 
*/

#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;
const int N = 15;

class BoundedOptimization{
	public:
		double mem[N][N],f[N][N],g[N][N];
		double ans,x[N][N],val[N],ms;
		int n,m,ad,state[N],lower[N],upper[N];
		string s;
		double maxValue(vector <string> expr, vector <int> lowerBound, vector <int> upperBound, int maxSum){
			int len = expr.size(),sum = 0;ms = maxSum;
			for (int i = 0;i < len;i++) s = s + expr[i];
			m = s.size();
			n = lowerBound.size();ad = n;
			for (int i = 0;i < n;i++) lower[i] = lowerBound[i],upper[i] = upperBound[i];
			for (int i = 0;i < n;i++) sum += upperBound[i];
			if (maxSum > sum){//������ֵ���ڶ˵㣬��Ϊ��ʱ������sigmaxi=max�� 
				int val = 1;
				for (int j = 0;j < m;j++){
					if ('a' <= s[j] && s[j] <= 'z')
						val *= upperBound[s[j]-'a'];
					else ans += val,val = 1;
				}
				ans += val;
				return ans;
			}
			int u = 0,v = 0; 
			for (int j = 0;j < m;j++){
				if ('a' <= s[j] && s[j] <= 'z'){
					if (u == 0) u = s[j]-'a';
					else v = s[j]-'a';
				}
				else{
					if (u < v) swap(u,v);
					mem[u][v]+=1;
					u = 0;v = 0;
				}
			}
			if (u < v) swap(u,v);
			mem[u][v]+=1;
			
			dfs(0);
			return ans;
		}
		void dfs(int p){
			if (p >= n){
				double tot = 0,sum = ms;
				memset(val,0,sizeof(val));
				memset(f,0,sizeof(f));
				for (int i = 0;i < n;i++){
					if (state[i] == 0) val[i] = lower[i];
					if (state[i] == 1) val[i] = upper[i];
					sum -= val[i];
				}
				
				for (int i = 0;i < n;i++)//ά������ 
					for (int j = 0;j <= i;j++)
						if (state[i] != 2 && state[j] != 2)
							f[ad][ad] += mem[i][j]*val[i]*val[j];
						else if (state[i] != 2) f[j][ad] += mem[i][j]*val[i];
						else if (state[j] != 2) f[i][ad] += mem[i][j]*val[j];
						else f[i][j] += mem[i][j]; 								
						
				int u = -1;//�ж��Ƿ�����xixj������ 
				for (int i = 0;i < n;i++)
					if (state[i] == 2){
						if (u == -1) u = i;
						bool flag = 1;
						for (int j = 0;j < i;j++)
							if (state[j] == 2)
								if (fabs(f[i][j]) < eps) flag = 0;
						if (!flag) return;
					}

				if (u != -1){//ע��������д𰸶��ڶ˵㡣 
					int cnt = 0;
					for (int i = 0;i < n;i++) 
						if (state[i] == 2) sum += f[u][ad]-f[i][ad],cnt++;
					sum /= cnt;

					for (int i = 0;i < n;i++) 
						if (state[i] == 2) val[i] = sum - (f[u][ad]-f[i][ad]);
				}
				sum = 0;//���Ƿ��ڷ�Χ�� 
				for (int i = 0;i < n;i++){
					if (val[i]-upper[i] > eps) return;
					if (lower[i]-val[i] > eps) return;
					sum += val[i];
				}

				if (fabs(sum-ms) > eps) return;	
				for (int j = 0;j < n;j++){
					for (int k = 0;k < j;k++){
						tot += mem[j][k]*val[j]*val[k];
					}
					tot += mem[j][ad]*val[j];
				}
				
				tot += mem[ad][ad];
				ans = max(ans,tot);
				return;
			}
			state[p] = 0;dfs(p+1);
			state[p] = 1;dfs(p+1);
			state[p] = 2;dfs(p+1);
		}
};
