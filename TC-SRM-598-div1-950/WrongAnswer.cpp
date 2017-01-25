// WAonSystemTest
#include <vector>
#include <string>
using namespace std;
class TPS{
public:
	int N,up[55],down[55],f[55]; // up[i]:i�Ϸ��Ƿ�Ϊ�� down[i]:i�·��Ƿ�Ϊ�� f[i]:i�ĸ��߱�ȡ�������i��������ȡ���ٸ���
	vector<int> to[55],ch[55]; // to[i]:i�ĳ��� ch[i]:i���ӽڵ�
	void cmin(int&a,int b){b<a?a=b:1;}
	void init(int i,int fa){ // Ԥ����up��ch
		for(int e=0,j;e<to[i].size();e++)
			if((j=to[i][e])!=fa)ch[i].push_back(j),init(j,i);
		down[i]=!ch[i].size()||ch[i].size()==1&&down[ch[i][0]];
	}
	void dfs(int i){ // ����down��f
		for(int c=0,j;c<ch[i].size();c++){
			j=ch[i][c];
			if(i)up[j]=up[i]&&ch[i].size()==1;
			else up[j]=ch[i].size()==1||ch[i].size()==2&&down[ch[i][!c]];
			dfs(j);
		}
		if(down[i]){f[i]=1;return;}
		f[i]=1<<30;
		// ���i����i���1��������ѡ���ұ�������
		int fmax=0,fsum=0;
		for(int c=0;c<ch[i].size();fsum+=f[ch[i][c++]])if(down[ch[i][c]])cmin(fmax,-f[ch[i][c]]);
		cmin(f[i],fsum+(ch[i].size()<1)); // ����������ѡ
		cmin(f[i],fsum+fmax+(ch[i].size()<2)); // 1��������ѡ
	}
	int minimalBeacons(vector <string> linked){
		if((N=linked.size())==1)return 0;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(linked[i][j]=='Y')to[i].push_back(j);
		init(0,-1);dfs(0);
		int ans=1<<30;
		for(int i=1;i<N;i++)if(up[i]){ // ö�����ĸ�i��i��ÿ������������ȡ
			// ���i��ѡ��Ҫ������2������
			int sum=ch[i].size()<2;
			for(int c=0;c<ch[i].size();c++)sum+=f[ch[i][c]];
			cmin(ans,sum);
		}
		// ��Ϊ0�����һ��������ѡ���ұ������� 
		int sum=0,fmax=0;
		for(int c=0;c<ch[0].size();sum+=f[ch[0][c++]])if(down[ch[0][c]])cmin(fmax,-f[ch[0][c]]);
		cmin(ans,sum+(ch[0].size()<2));
		cmin(ans,sum+fmax+(ch[0].size()<3));
		return ans;
	}
};
