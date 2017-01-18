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
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,A[N],B[N];

class TheNumberGame{
	public:
	string determineOutcome(int a,int b)
	{
		  while (a) A[++A[0]]=a%10,a/=10;
		  while (b) B[++B[0]]=b%10,b/=10;
		  for (i=1;i<=A[0];++i) //���ǵ�len(A),len(B)<=9,��������1000��,��ôֻҪ����A��B���Ӵ�,A��һ���ܹ���B,ֻҪʱ�̱�ֽA��B��B�ķ�ת�ĳ�������. 
		  {
		    for (j=1;j<=B[0];++j)
		      if (B[j]!=A[i+j-1]) break;
		    if (j>B[0]) return "Manao wins";
		  }
		  for (i=1;i<=B[0]/2;++i) swap(B[i],B[B[0]-i+1]);
		  for (i=1;i<=A[0];++i)
		  {
		    for (j=1;j<=B[0];++j)
		      if (B[j]!=A[i+j-1]) break;
		    if (j>B[0]) return "Manao wins";
		  }
		  return "Manao loses";
	}
};
