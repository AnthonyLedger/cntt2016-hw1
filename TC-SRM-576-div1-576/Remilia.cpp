#include<bits/stdc++.h>

#define rep(x,a,b) for (int x=a;x<=(int)b;x++)
#define drp(x,a,b) for (int x=a;x>=(int)b;x--)
#define cross(x,a) for (int x=hd[a];~x;x=nx[x])
#define ll long long
#define inf (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fs first
#define sc second
#define pb push_back
#define VI vector<int>
using namespace std;
#define mod 1000000009
const int maxn=305;
string s;
int n,wat[maxn],pre[maxn];
int f[2][maxn][maxn][2];
void upd(int &x,int y){
	if (y>=mod) y%=mod;
	x=(x+y)%mod;
}

/*
����DP��

����ö����ȫ���ӵ������ӣ���ôʣ�µı����ֳ����ɸ����䣬ÿ���������治��������¶���������ӡ�

��f[l][r][0,1,2]��ʾ��һ������������0��1��2�����ӵķ���������󱳰�һ�鼴�ɡ�
*/

struct TheExperiment{
	int countPlacements(vector<string>inten,int M,int L,int A,int B){
		rep(i,0,inten.size()-1) s+=inten[i];
		n=s.size();
		rep(i,1,n) wat[i]=s[i-1]-'0',pre[i]=pre[i-1]+wat[i];
		int fr=0,to=1;
		f[fr][0][0][0]=1;
		rep(i,1,n){
			memset(f[to],0,sizeof f[to]);
			rep(j,0,M) rep(k,0,L) rep(l,0,1){
				if (!f[fr][j][k][l]) continue;
				int v=f[fr][j][k][l];
				if (!k){
					if (j<M) upd(f[to][j][1][L==1],v);
					upd(f[to][j][0][0],v);
				}
				else{
					int sum=pre[i-1]-pre[i-k-1];
					if (sum>B) continue;
					if (sum>=A){
						if (j<M-1) upd(f[to][j+1][1][l],v);
						if (l) upd(f[to][j+1][0][0],v);
					}
					if (sum+wat[i]<=B&&k<L) upd(f[to][j][k+1][l|(k+1==L)],v);
				}
			}
			fr^=1,to^=1;
		}
		int ans=f[fr][M][0][0];
		rep(i,1,L){
			if (pre[n]-pre[n-i]>B) break;
			if (pre[n]-pre[n-i]<A) continue;
			upd(ans,f[fr][M-1][i][1]);
		}
		return ans;
	}
};
/*
f[i][l][j][k]��ʾ��ǰ������iλ���Ѿ�����j�����裬��ǰ����ӵ��ĳ���Ϊk��l��ʾ��һ���Ƿ��Ѿ��г�����������,�����ķ�����
ת��ʱö����λȡ��ȡ 
*/ 
