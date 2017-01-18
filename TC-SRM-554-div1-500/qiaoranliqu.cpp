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

#define N 55
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,A[N],Ans[N],vis[N],ANS[N],ID[N],sum[N],l;
inline bool cmp(int a,int b)
{
		if (A[a]!=A[b])
		return A[a]<A[b];
		return a<b;
}
class TheBrickTowerMediumDivOne{
	public:
		vector <int> find(vector <int> heights)
		{
			n=heights.size();
			for (i=0;i<n;++i) A[i]=heights[i],ID[i]=i,ANS[i]=1000000;
			sort(ID,ID+n,cmp); 
			for (i=0;i<n;++i) //ö�ٸ߶���С�Ļ�ľ��λ�� 
			{
				 memset(Ans,-1,sizeof(Ans));
				 memset(vis,0,sizeof(vis));
				 Ans[i]=ID[0]; vis[0]=1;
				 int last=10000000;
				 for (j=0;j<i;++j) //�������Ұ��ֵ�����Сԭ������ 
				 {
				 		int nowID=N,nowsum=0;
				 	   int dist=i-j;
				 	   memset(sum,0,sizeof(sum));
				 	   for (k=0;k<n;++k) //�����ÿ����С�����ĸ��� 
				 	   	 if (!vis[k])
				 	   	   for (l=0;l<n;++l) 
							   	if (A[ID[k]]<=A[ID[l]]) sum[l]++;
				 	   for (k=0;k<n;++k) //��һ�����������ı����С���� 
				 	   	 if (!vis[k]&&sum[k]>=dist&&ID[k]<nowID&&(!j||A[ID[last]]>=A[ID[k]]))
				 	   	    nowID=ID[k],nowsum=k;
				 	   Ans[j]=nowID; vis[nowsum]=1; last=nowsum;
				 }
				 for (j=i+1;j<n;++j) //���ұߵ������ 
				 	for (k=0;k<n;++k)
				 		if (!vis[k])
				 		{
				 				vis[k]=1;
				 				Ans[j]=ID[k];
				 				break;
				 		}
				 for (j=0;j<n;++j) if (Ans[j]!=ANS[j]) break;
				 if (Ans[j]<ANS[j]) //�Ƚ�������ͬ�����ֵ���Ĵ�С. 
				   for (j=0;j<n;++j) ANS[j]=Ans[j]; 
			}
			vector<int>ans;
			for (i=0;i<n;++i) ans.pb(ANS[i]);
			return ans;
		}
};
