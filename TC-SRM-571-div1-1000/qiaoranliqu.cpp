#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 55
#define M 50005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,vis[N],Q[M];
double low[N],high[N];
double sqr(double x)
{
		return x*x;
}
double dis(double ax,double ay,double bx,double by)
{
		return sqrt(sqr(ax-bx)+sqr(ay-by));
}
void New(int ID,double S,double T)
{
	 if (low[ID]>S||high[ID]<T) //�����µ�low��high 
	 {
	 		Q[++Q[0]]=ID;
	 		low[ID]=min(low[ID],S);
	 		high[ID]=max(high[ID],T);
	 }
}
class CandyOnDisk{
	public:
		string ableToAchieve(vector <int> x, vector <int> y, vector <int> r, int sx, int sy, int tx, int ty)
		{
				if (sx==tx&&sy==ty) return "YES";
				n=x.size();
				for (i=0;i<n;++i) low[i]=1e9,high[i]=-1.;
				for (i=0;i<n;++i)
					if (dis(x[i],y[i],sx,sy)<=r[i])
						low[i]=high[i]=dis(x[i],y[i],sx,sy); 
				for (i=0;i<n;++i) Q[++Q[0]]=i;
				int l=1;
				for (;l<=Q[0];++l)  
				{
						int p=Q[l];
						for (i=0;i<n;++i) //ö��������һ��Բ,Ȼ������Բ���ϸ��µ����ս�,���׷��ֵ�һ�θ���֮��,����(p,i)����ԾͲ����ٸ����� 
							if (i!=p)
							{
								if (x[i]!=x[p]||y[i]!=y[p])
								{
									double D=dis(x[i],y[i],x[p],y[p]);
									double S=max(D-r[i],0.),T=min(D+r[i],(double)r[p]);
									if (max(S,low[p])<=min(T,high[p])) //�ж�����Բ��ǰ�ܷ��໥���� 
									{
									 	New(p,S,T);
									 	New(i,max(D-r[p],0.),min(D+r[p],(double)r[i]));
									}
								}
								else 
								{
									New(p,low[i],min(high[i],(double)r[p]));
									New(i,low[p],min(high[p],(double)r[i]));
								}
							}
				}
				for (i=0;i<n;++i)
				{
					double D=dis(x[i],y[i],tx,ty);
					if (low[i]<D&&D<high[i]) return "YES";
				}
				return "NO";
		}
};

