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
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k;
string s[N];
int C(int x,int y)
{
		if (x<y) return 0;
		return 1;
}
int Lucas(long long x,long long y) //����lucas��������� 
{
		if (x<y) return 0; 
		if (y==0) return 1;
		return Lucas(x/2,y/2)*C(x%2,y%2);
}
class CheckerExpansion{
	public:
	vector <string> resultAfter(long long t,long long x0,long long y0,int w,int h)
	{
			for (i=0;i<w;++i) 
				for (j=0;j<h;++j) 
				{
						s[i]+=' ';
						if (x0+i+y0+j>2*(t-1)) s[i][j]='.'; //������������Ƿ���ʱ�����ܴﵽ 
						else if ((x0+i+y0+j)&1) s[i][j]='.'; //���еĵط���ֻ�п�����ż�� 
						else if (Lucas((x0+i+y0+j)/2,y0+j)==0) s[i][j]='.'; //��������(a_(x,y)=a_(x-2,y)^a(x-1,y-1),����һά��Ϊ(x+y)/2��ת��Ϊģ2�����µ������ 
						else
						{
							if ((x0+i+y0+j)%4==0) s[i][j]='A';
							else s[i][j]='B';
						}
				}
		  vector<string>ans;
		  for (i=0;i<h;++i) //����ת����ʽ��� 
		{
			string c="";
			for (j=0;j<w;++j)
			c+=s[j][h-i-1];
			ans.pb(c);
			cout<<c<<endl;
		}
		return ans;
	}
}MRT;

int main()
{
	MRT.resultAfter(1,0,0,4,4);
}
