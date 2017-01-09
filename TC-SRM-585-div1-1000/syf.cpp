//============================================================================
// Author       : Sun YaoFeng
//============================================================================

//#pragma 	comment(linker, "/STACK:100240000,100240000")
//#include	<cstdio>
//#include	<cstdlib>
//#include	<cstring>
//#include	<algorithm>

#include	<bits/stdc++.h>

using	namespace	std;

#define DB		double
#define	lf		else if
#define I64		long long
#define	Rd()	(rand()<<15|rand())
#define For(i,a,b)	for(int i=a,lim=b;i<=lim;i++)
#define Rep(i,a,b)	for(int i=a,lim=b;i>=lim;i--)

#define	fi	first
#define se	second
#define MK	make_pair
#define PA	pair<int, int>

//#define	min(a,b)	((a)<(b)?(a):(b))
//#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

#define n	250005

int		T, M, L[n], R[n], H[n];

I64		Ans, Sum;

struct	Nod{
		int x, y;
		
		Nod	operator -	(const Nod&b)	const{
			return	(Nod){x-b.x, y-b.y};
		}
		
		I64	operator *	(const Nod&b)	const{
			return	1ll*x*b.y - 1ll*y*b.x;
		}
}A[n], B[n];

bool	check(int u, int v)	{	//���
		For(i, 1, M)	if	((B[i]-A[u]) * (A[v]-A[u]) < 0)	return	0;
		return	1;
}

int		Cal(int l1, int r1, int l2, int r2)	{	//�߶��н�
		return	max(0, min(r1, r2) - max(l1, l2) + 1);
}

class	EnclosingTriangle{
	public:
		I64		getNumber(int N, vector <int> x, vector <int> y){
			M= x.size();
			For(i, 1, M)	B[i]= (Nod){x[i-1], y[i-1]};
			
			For(i, 0, N-1)	A[++ T]= (Nod){0, i};
			For(i, 0, N-1)	A[++ T]= (Nod){i, N};
			Rep(i, N, 1)	A[++ T]= (Nod){N, i};
			Rep(i, N, 1)	A[++ T]= (Nod){i, 0};	//���߽��ϵĵ��������
			
			for (int i= 1, j= 2; i <= T; i++)	{	//Ԥ����ÿһ�������ҿ��Կ�������
				for (; j <= T && check(i, j); j++);
				R[i]= j-1;
			}
			
			for (int i= 1, j= 2; i <= T; i++)	{	//Ԥ����������Կ�������
				for (; j <= T && ! check(j, i); j++);
				L[i]= j;
			}
			
			for (int i= 2, j= 1; i <= T; i++)	{	//��N��ʼ���ſ��Կ�������
				for (; ! check(j, i); j++);
				H[i]= j;
			}
			
			For(i, 2, R[1])	Sum+= Cal(i+1, R[i], L[1], T);
			Ans= Sum;
			
			For(i, 2, T)	{	//ö���е�
				Sum-= Cal(i+1, R[i], L[i-1], T);	//���õ����Եõ��µĴ�
				For(j, R[i-1]+1, R[i])	Sum+= Cal(j+1, R[j], L[i-1], T);	
				For(k, L[i-1], L[i]-1)	Sum-= Cal(H[k], k-1, i+1, R[i]);
				Ans+= Sum;
			}
			
			return	Ans;
		}
}GTW;