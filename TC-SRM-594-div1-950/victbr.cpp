#include<bits/stdc++.h>

using namespace std;

class FoxAndAvatar{
	public:
		int w;
		int minimalSteps(int n, int width, int x){
			w = width;
			if (n == 1) return 0;
			return dfs(n,w,x,0);
		}
		int dfs(int n,int w,int x,int d){	
			if (x == w && n < w*2) return 1;
			if (x == n && n%w == 1) return 1;
			if (n <= w && x == 1) return 1;
			if (n <= w && x == n) return 1;
			if (w == 1 && x == 1) return 1;
			if (w == 1 && x == n) return 1;
			if (d >= 2) return 2;//����Ѿ���������������һ��֮�����꣬��һ�������4�ǡ� 
			int k = (x-1)/w,ans = 4,o = (n-1)/w,p = (n-1)%w+1,e = (x-1)%w+1;
			if (n <= w) return 2;
			ans = min(ans,dfs(min(n,(k+1)*w),w,x,d+1)+1);//������ȫ��ȥ��Ҳ���������Ž� 
			for (int i = 0;i <= k;i++)//x�����ڵ�һ�У�����Ҫ��0��ʼ 
				for (int j = 0;j <= w;j++){
					ans = min(ans,dfs(n-i*j,w,x-i*j,d+1)+1);
					
					int u = 0;
					if (j < p) u = j;
					else u = p;
					if (j < e){
						ans = min(ans,dfs(n-(i+o-k)*j-u,w,x-j*(i+1),d+1)+1);
					}
					if (e+j <= w){
//						if (n == 26 && x == 14 && j == 5) cout << d<<"A" << endl;
						int v = 0;
						if (p-e >= j) v = j;
						else v = max(0,p-e); 
						ans = min(ans,dfs(n-(i+o-k)*j-v,w,x-i*j,d+1)+1);
					}
				}
			for (int j = 1;j < e;j++)
				ans = min(ans,dfs(n-j*(k+1),w,x-j*(k+1),d+1)+1);
			
			return ans;
		}
}; 
