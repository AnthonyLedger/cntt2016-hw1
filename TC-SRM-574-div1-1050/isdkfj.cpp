#include <bits/stdc++.h>

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
int n,m,cnt,col[55][55],mn[5555],mx[5555],lu[55],ld[55],ru[55],rd[55],lr[55],deg[55][55],f[55][55][55];
char mp[55][55];

void dfs(int x,int y){//������ͨ�� 
	col[x][y]=cnt;
	for(int k=0;k<4;++k){
		int xx=x+dx[k],yy=y+dy[k];
		if(0<=xx&&xx<n&&0<=yy&&yy<m&&mp[xx][yy]=='X'&&!col[xx][yy])dfs(xx,yy);
	}
}

class Tunnels {
public:
	int minimumTunnels(vector <string> frame) {
		n=frame.size();
		m=frame[0].size();
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)mp[i][j]=frame[i][j];
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			if(mp[i][j]=='X'&&!col[i][j]){
				++cnt;
				dfs(i,j);
			}
		if(m==1)return cnt>0?1:0;//���У����ֻ��һ�У���X���Դ����� 
		for(int i=1;i<=cnt;++i)mn[i]=n,mx[i]=-1;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			if(mp[i][j]=='X'){
				mn[col[i][j]]=min(mn[col[i][j]],i);
				mx[col[i][j]]=max(mx[col[i][j]],i);//��ÿ����ͨ������Ϸ��ĵ�����·��ĵ� 
			}
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				for(int k=0;k<4;++k){
					int x=i+dx[k],y=j+dy[k];
					if(0<=x&&x<n&&0<=y&&y<m&&mp[x][y]=='X')++deg[i][j];//ÿ����Ķ��� 
				}
		for(int i=0;i<n;++i)
		if(mp[i][0]=='X'&&deg[i][0]<=1){
			if(i==mn[col[i][0]])lu[i]=1;//���Ϸ������������� 
			if(i==mx[col[i][0]])ld[i]=1;//���·������������� 
			if(i>1)ld[i]&=!lu[i-1];//�������ڵ������飬����Ŀ鲻���ٵ�һ�У���һ�п���ֱ�ӵ����ڣ� 
		}
		for(int i=0;i<n;++i)//�����һ�� 
		if(mp[i][m-1]=='X'&&deg[i][m-1]<=1){
			if(i==mn[col[i][m-1]])ru[i]=1;
			if(i==mx[col[i][m-1]])rd[i]=1;
			if(i>1)rd[i]&=!ru[i-1];
		}
		for(int i=0;i<n;++i)lr[i]=col[i][0]==col[i][m-1]&&col[i][0];
		for(int i=1;i<n;++i){
			int c1=col[i][0];
			int c2=col[i][m-1];
			if(c1!=c2){ 
				if(c1&&mx[c1]==mn[c1])ld[i]=0;
				if(c2&&mx[c2]==mn[c2])rd[i]=0;
				//ֻ��ĳ�ߵ�һС�Σ����������� 
			}
		}
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				for(int k=0;k<=n;++k)
				f[i][j][k]=-999999999;//��ʼ�� 
		f[n][0][0]=0;
		for(int k=n-1;k>=0;--k)
			for(int i=0;i<=k;++i)
				for(int j=0;j<=k;++j)
					for(int a=-1;a<=1;++a)
						for(int b=-1;b<=1;++b)
						//-1:����ƥ�� 
						//0:ֱ�ӽӳ���
						//1:����ƥ�� 
						if((a!=1||ld[k])&&(b!=1||rd[k])&&(a!=-1||lu[k])&&(b!=-1||ru[k])&&(a==0||b==0||a!=b||!lr[k])&&(i+a>=0)&&(j+b>=0))
							f[k][i][j]=max(f[k][i][j],f[k+1][i+a][j+b]+(a>0)+(b>0));
		return cnt-f[0][0][0];
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
