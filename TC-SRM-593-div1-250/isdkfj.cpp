#include <bits/stdc++.h>

using namespace std;

int col[55][55],cnt,n;

#define _(dx,dy) if((x+dx)>=0&&(x+dx)<n&&(y+dy)>=0&&(y+dy)<n&&a[x+dx][y+dy]=='X'){\
	if(col[x+dx][y+dy]==-1){\
		col[x+dx][y+dy]=col[x][y]^1;\
		if(!dfs(x+dx,y+dy,a))return 0;\
	}else if(col[x+dx][y+dy]==col[x][y])return 0;\
}

bool dfs(int x,int y,vector<string>&a){
	++cnt;//��ĸ��� 
	_(-1,0)
	_(-1,1);
	_(0,-1);
	_(0,1);
	_(1,-1);
	_(1,0);//�������� 
	return 1;
}

class HexagonalBoard {
public:
	int minColors(vector <string> board) {
		int mx=0,flag=1;
		n=board.size();
		memset(col,-1,sizeof col);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			if(board[i][j]=='X'&&col[i][j]==-1){
				cnt=0;
				col[i][j]=0;
				flag&=dfs(i,j,board);//�Ƿ��Ƕ���ͼ 
				mx=max(mx,cnt);//������ͨ���С 
			}
		if(flag){
			if(mx==0)return 0;
			if(mx==1)return 1;
			return 2;
		}
		return 3;//��Ȼ������������ɫ��� 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
