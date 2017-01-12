#include <bits/stdc++.h>

using namespace std;

const int dx[]={0,0,-1,1},dy[]={1,-1,0,0},mo=1e9+9;
vector<string>mp;
bool g[44][44][44][44],vis[44][44];
int n,m,cnt,pw[4444];
struct pot{
	int a,b,c,d;
	pot(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
};
bool chk(int x,int y){//�Ƿ��ڸ����� 
	return 0<=x&&x<n&&0<=y&&y<m;
}
void nxt(int&i,int&j,int x,int y,int k){//����ĳ��������һ�� 
	i=x+dx[k];j=y+dy[k];
	if(chk(i,j)&&mp[i][j]=='#')i=x,j=y;
}
void dfs(int x,int y){//������ͨ���С 
	vis[x][y]=1;++cnt;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		if(mp[i][j]!='#'&&!g[x][y][i][j]&&!vis[i][j])dfs(i,j);
}

class CoinsGame {
public:
	int ways(vector <string> board) {
		mp=board;n=board.size(),m=board[0].size();
		queue<pot>q;
		for(int x1=0;x1<n;++x1)
			for(int y1=0;y1<m;++y1)
			if(mp[x1][y1]!='#')
				for(int x2=0;x2<n;++x2)
					for(int y2=0;y2<m;++y2)if(mp[x2][y2]!='#'){
						int i1,j1,i2,j2;
						for(int k=0;k<4;++k){
							nxt(i1,j1,x1,y1,k);
							nxt(i2,j2,x2,y2,k);
							if((chk(i1,j1)^chk(i2,j2))&&!g[x1][y1][x2][y2]){
								g[x1][y1][x2][y2]=1;
								q.push(pot(x1,y1,x2,y2));//�ҳ�һ���͵���ȥ�ĵ� 
							}
						}
					}
		while(!q.empty()){
			pot t=q.front();q.pop();
			for(int i=0;i<4;++i)
				for(int j=0;j<2;++j)
					for(int k=0;k<2;++k){
						int x1=t.a+(j?dx[i]:0),y1=t.b+(j?dy[i]:0),x2=t.c+(k?dx[i]:0),y2=t.d+(k?dy[i]:0);
						if(!chk(x1,y1)||!chk(x2,y2))continue;
						if(g[x1][y1][x2][y2])continue;
						if(mp[x1][y1]=='#'||mp[x2][y2]=='#')continue;
						int i1,j1,i2,j2;
						nxt(i1,j1,x1,y1,i^1);
						nxt(i2,j2,x2,y2,i^1);
						if(i1==t.a&&j1==t.b&&i2==t.c&&j2==t.d){//���ߵ� 
							g[x1][y1][x2][y2]=1;
							q.push(pot(x1,y1,x2,y2));
						}
					}
		}
		int ans=0,sum=0;
		pw[0]=1;for(int i=1;i<=n*m;++i)pw[i]=pw[i-1]*2%mo;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			if(mp[i][j]!='#'){
				if(!vis[i][j]){
					cnt=0;dfs(i,j);
					ans=(ans+pw[cnt]-1)%mo;//�۵�һ���㶼��ȡ����� 
				}
				++sum;
			}
		ans=(pw[sum]-ans+mo)%mo;
		ans=(ans-1+mo)%mo;
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
