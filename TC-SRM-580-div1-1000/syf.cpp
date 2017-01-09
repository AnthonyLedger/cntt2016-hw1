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

#define n	55
#define INF	(1 << 30)

int		N, M, Tim, A[n][n], S[n][n];

int		F[n][n][n][2], V[n][n][n][2];

int		Work(int d, int l, int r, int t)	{	//���仯������F[i][j][k][t] ��ʾA�ڵ�i��[j,k]�����������Ҷ˵��ϣ�B�Ѹ������j-k�ϡ�
		if	(d == N)	return	0;
		if	(V[d][l][r][t] == Tim)	return	F[d][l][r][t];
		V[d][l][r][t]= Tim;
		
		if	(t)	{
			int	ret= Work(d+1, r+1, r, 1) + A[d+1][r+1];	//ö�������߻��������ߣ�ѡ���ŵ�
			
			if	(r-l+1 < M-1)	{
				int v= INF;
				if	(r+1 < M)	v= min(v, Work(d, l, r+1, 1) + A[d][r+2]);
				if	(l > 1)		v= min(v, Work(d, l, r+1, 0) + S[d][r] - S[d][l-2]);
				ret= max(ret, v);
			}
			
			F[d][l][r][t]= ret;
		}
		else	{
			int ret= Work(d+1, l-1, l-2, 1) + A[d+1][l-1];
			
			if	(r-l+1 < M-1)	{
				int v= INF;
				if	(l-1 > 1)	v= min(v, Work(d, l-1, r, 0) + A[d][l-2]);
				if	(r < M)		v= min(v, Work(d, l-1, r, 1) + S[d][r+1] - S[d][l-1]);
				ret= max(ret, v);
			}
			
			F[d][l][r][t]= ret;
		}
		
		return	F[d][l][r][t];
}

class	WallGameDiv1{
	public:
		int 	play(vector <string> costs){
			N= costs.size();
			M= costs[0].length();
			
			For(i, 1, N)	For(j, 1, M)	{
				A[i][j]= costs[i-1][j-1] - '0';
				S[i][j]= S[i][j-1] + A[i][j];
			}
			
			//Ԥ����
			
			int	Ans= INF;
			For(i, 1, M)	{	//ö��A��������
				Tim++;
				Ans= min(Ans, Work(1, i, i-1, 1) + A[1][i]);
			
	//			printf("%d\n", Work(1, i, i-1, 1) + A[1][i]);
			}
			
			return	Ans;
		}
}GTW;