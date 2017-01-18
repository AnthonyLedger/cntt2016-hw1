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

#define N 305
#define seed 23333
#define Mo 1000000009

using namespace std;
int i,j,m,n,p,k,sum[N],f[N][N],g[N][N],h[N][N],A,B;
int check(int x,int y)
{
	return sum[y]-sum[x]>=A&&sum[y]-sum[x]<=B;
}
void jia(int &x,int y)
{
		x+=y; if (x>=Mo) x-=Mo; 
}
class TheExperiment{
	public:
	int countPlacements(vector <string> intensity, int M, int L, int A, int B)
	{
			string s; ::A=A;::B=B;
			for (i=0;i<(int)intensity.size();++i) s+=intensity[i];
			n=s.length();
			for (i=1;i<=n;++i) sum[i]=sum[i-1]+s[i-1]-'0';
			f[0][0]=1;
			for (i=1;i<=n;++i) //��f_{i,j}Ϊ��ǰ����i,����j��������i���˷ѵķ���.g/h_{i,j}��ʾi�������ס,�ҵ�ǰ����/��һ������=L������,ÿ������Ϸ�����������һ��Ҫ������һ������ΪL������ 
			{
					for (j=0;j<=M;++j)
					{
						jia(f[i][j],f[i-1][j]); //�˷�һ��ˮ��ͷ 
						jia(f[i][j],h[i-1][j]);
						if (j&&i>=L&&check(i-L,i)) jia(h[i][j],f[i-L][j-1]), //����һ������ΪL������ 
												   jia(h[i][j],g[i-L][j-1]);
						for (k=i-1;j&&k>=0&&i-k<=L;--k) //����һ������С��L������ 
							if (check(k,i))
						{
								if (i-k<L)
								{
									jia(g[i][j],f[k][j-1]);
									jia(g[i][j],g[k][j-1]);
								}
								jia(h[i][j],h[k][j-1]);
						}
					}
			}
			return (f[n][M]+h[n][M])%Mo;
	}
}MRT;

int main()
{
	MRT.countPlacements({"341156"},3,3,6,10);
}
