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
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,f[N][2][2],ans;
void jia(int &x,int y)
{
	x+=y; if (x>=Mo) x-=Mo;
}
class DefectiveAddition{
	public:
		int count(vector <int> cards, int n)
		{
				m=cards.size();
				for (i=30;i>=0;--i) //ö�ٴ���һλ��ʼ������һ��B_i��һλԭ����1,������0,���������Ϊ��������������ѡ��֮����ܵõ�n�ı��� 
				{
						for (k=30;k>i;--k) //ǰ׺����Ҫ�������� 
						{
							 int x=n&(1<<k);
							 for (j=0;j<m;++j) x^=(cards[j]&(1<<k));
							 if (x) break;
						}
						if (k!=i) continue;
						memset(f,0,sizeof(f));
						f[0][0][0]=1;
						for (j=0;j<m;++j) //��f_{i,j,k}Ϊ����ǰi����,��ǰ��λ��j,���Ƿ��������һ����ʹ�����ܹ�����ʹ�� 
						//����cards_i��һλ�ϵ����������ת�� 
						{
								int now=((cards[j]&(1<<k))>0);
								jia(f[j+1][now][0],1ll*f[j][0][0]*((cards[j]&((1<<i)-1))+1)%Mo);
								jia(f[j+1][now^1][0],1ll*f[j][1][0]*((cards[j]&((1<<i)-1))+1)%Mo);
								if (now==1)
								{
									jia(f[j+1][1][1],1ll*f[j][0][1]*((cards[j]&((1<<i)-1))+1)%Mo);
									jia(f[j+1][0][1],1ll*f[j][1][1]*((cards[j]&((1<<i)-1))+1)%Mo);
									jia(f[j+1][0][1],1ll*f[j][0][1]*(1<<i)%Mo);
									jia(f[j+1][1][1],1ll*f[j][1][1]*(1<<i)%Mo); 
								}
								else 
								{
									jia(f[j+1][0][1],1ll*f[j][0][1]*((cards[j]&((1<<i)-1))+1)%Mo);
									jia(f[j+1][1][1],1ll*f[j][1][1]*((cards[j]&((1<<i)-1))+1)%Mo);									
								}
								if (now==1) //������Ϊ���ɻ� 
								{
									jia(f[j+1][0][1],f[j][0][0]);
									jia(f[j+1][1][1],f[j][1][0]);
								}
						}
						jia(ans,f[m][(n&(1<<i))>0][1]);
				}
				int s=0;
				for (i=0;i<m;++i) s^=cards[i];
				if (s==n) jia(ans,1);
				return ans;
		}
};
