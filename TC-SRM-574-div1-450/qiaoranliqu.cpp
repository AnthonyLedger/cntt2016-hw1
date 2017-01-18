#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 18
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,A[M][M],B[M][M];
long long f[1<<M][M];
class PolygonTraversal{
	public:
		long long count(int n,vector<int> v)
		{
			  m=v.size(); int str=0;
			  for (i=0;i<(int)v.size();++i)
			  {
			  	     v[i]--;
			  	     str|=(1<<v[i]);
		      }
		      f[str][v[v.size()-1]]=1;
		      for (i=0;i<n;++i)
		        for (j=0;j<n;++j)
		          if (i!=j)
		          {
		          	   for (k=i;k!=j;k=(k+1)%n) A[i][j]|=(1<<k);
					   A[i][j]-=(1<<i);
					   for (k=i;k!=j;k=(k+n-1)%n) B[i][j]|=(1<<k);
					   B[i][j]-=(1<<i);
				  }
			  for (i=0;i<(1<<n);++i)  //��f_{i,j}Ϊ�㼯i�Ѿ�������,�����һ��Ϊj�ķ��� 
			    for (j=0;j<n;++j)
			      if (f[i][j]) 
			      {
			      	    for (k=0;k<n;++k)
			      	    {
			      	      if (i&(1<<k)) continue;
			      	      if ((A[j][k]&i)&&(B[j][k]&i)) f[i|(1<<k)][k]+=f[i][j]; //��ô(j,k)�Ϸ����ҽ���(j,k)�߶����඼�е�,Ԥ����ÿ���߶�����ĵ㼴��O(1)�ж� 
			      	    }
			      }
			  int Maxn=(1<<n)-1;
			  long long ans=0;
			  for (j=0;j<n;++j) if (f[Maxn][j]) 
			  {
			  	    if (j!=(v[0]+n-1)%n&&j!=(v[0]+1)%n) ans+=f[Maxn][j]; 
			  }
			  return ans;
		}
};
