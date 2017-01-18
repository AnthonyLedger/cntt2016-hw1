#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

#define N 305

using namespace std;

string sa,sb;
int i,n,dis[N],Q[N];
double ans;
struct Node{
	  int d[N];
	  vector<int> v[N];
	  void ins(int x,int y) { v[x].push_back(y); v[y].push_back(x); }
	  void bfs(int x)
	  {
	  	  int i;
	  	   Q[Q[0]=1]=x;
	  	   memset(dis,-1,sizeof(dis));
	  	   dis[x]=1;
	  	   int l=1;
	  	   for (l=1;l<=Q[0];++l)
		   {
		        int p=Q[l];
				for (i=0;i<(int)v[p].size();++i)
				{
				     int k=v[p][i];
					 if (dis[k]!=-1) continue;
					 dis[k]=dis[p]+1;
					 Q[++Q[0]]=k;
				}
		   }
		   for(i=0;i<n;++i) d[dis[i]]++;
	  }
	  void work()
	  {
	  	  int i;
	  	  for (i=0;i<n;++i) bfs(i); 
	  }
}A[2];
class TreeUnion{
	public:
	double expectedCycles(vector<string> a,vector<string> b,int K) //������ÿ������ÿ���϶�������������,��������K<=7,�����ڵڶ�������ֻ��һ��,�ڵ�һ������Ҳֻ��һ��,���㳤��Ϊi�������ȼ���. 
	{
		   for (i=0;i<a.size();++i) sa+=a[i];
		   for (i=0;i<b.size();++i) sb+=b[i];
		   sa+=' '; sb+=' ';
		   n=1;
		   for (i=1;i<=sa.length();++i) if (sa[i]==' ') ++n;
		   int L=0;
		   for (i=1;i<n;++i)
		   {
		   	    int sum=0;
		   	    while (sa[L]!=' ') sum=sum*10+sa[L]-'0',++L;
		   	    ++L;
		   	    A[0].ins(sum,i);
		   }
		   L=0;
		   for (i=1;i<n;++i)
		   {
		   	    int sum=0;
		   	    while (sb[L]!=' ') sum=sum*10+sb[L]-'0',++L;
		   	    ++L;
		   	    A[1].ins(sum,i);
		   }
		   A[0].work(); A[1].work();
		   for (i=2;i<=K-2;++i) ans+=1ll*A[0].d[i]*A[1].d[K-i]/2;
		   return 1.*ans/(n-1)/n; 
	}
}FFT;
int main()
{
	  vector<string> a,b; a.push_back("0"); b.push_back("0");
	  FFT.expectedCycles(a,b,4);
}
