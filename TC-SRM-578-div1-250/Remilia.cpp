// by ��
// program sky  :)

#include <vector>
#include <stdio.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)
#define ALL(V) V.begin(),V.end()
#define pb push_back
#define mk make_pair
#define x first
#define y second

using namespace std;

typedef double db;
typedef long long LL;
typedef pair<int ,int> PII;
typedef pair<db ,db> cpx;
typedef vector<int> VI;
typedef vector<PII> VII;

int odd,even,D,n,m,sz,bo[55][55],a[55][55],up[55][55],dn[55][55];

void gao(int i,int j){
	if(bo[i][j])return;
	++sz;
	bo[i][j]=1;
	For(p,1,m){
		int k=i;
		if(abs(i-k)+abs(j-p)<=D && a[k][p])gao(k,p);
		k=up[i-1][p];
		if(abs(i-k)+abs(j-p)<=D)gao(k,p);
		k=dn[i+1][p];
		if(abs(i-k)+abs(j-p)<=D)gao(k,p);
	}
	//�ҵ�ÿ����������������㣬����
}

int Main(){
	For(j,1,m){
		up[0][j]=-10000;
		For(i,1,n)up[i][j]=a[i][j]?i:up[i-1][j];
		dn[n+1][j]=10000;
		dto(i,n,1)dn[i][j]=a[i][j]?i:dn[i+1][j];
	}
	For(i,1,n)For(j,1,m)if(a[i][j] && !bo[i][j]){
		//���δ���ÿ��û�д��������ͨ��
		sz=0;
		gao(i,j);
		if(sz&1)++odd;else ++even;
		//��������ͨ��Ĵ�С����������ż��
	}
	int A=0;
	if(odd)A=odd+even-1;else A=even;
	int re=1;
	for(;A--;)re=re*2%1000000007;
	return re-1;//��Ϊ��2���ݴΣ���˲������ģPΪ0�����
	//�𰸼��㷽ʽ��2^(max(odd,1)+even-1)-1
}

struct GooseInZooDivOne{
	int count(vector <string> field, int dist){
		n=field.size();m=field[0].size();
		rep(i,0,n)rep(j,0,m)a[i+1][j+1]=field[i][j]=='v';
		D=dist;
		//��ȡ����
		return Main();
	}
};