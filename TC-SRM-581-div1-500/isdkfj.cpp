#include <bits/stdc++.h>

using namespace std;

int f[305][305],cnt1[305],cnt2[305],n;

void work(vector<string>tree,int*cnt){
	string s;
	for(int i=0;i<tree.size();++i)s+=tree[i];
	stringstream ss(s);
	memset(f,0x3f,sizeof f);
	n=0;
	int a;
	while(ss>>a){
		++n;
		f[a][n]=f[n][a]=1;//��ʼ�� 
	}
	++n;
	for(int i=0;i<n;++i)f[i][i]=0;
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);//floyd 
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)++cnt[f[i][j]];//���ÿ�ֳ��ȵ�·���� 
}

class TreeUnion {
public:
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
		work(tree1,cnt1);
		work(tree2,cnt2);
		K-=2;//�м����� 
		double ans=0;
		for(int i=1;i<K;++i)//ö�ٵ�һ�����еĳ��� 
			ans+=1.*cnt1[i]*cnt2[K-i]/n/(n-1)/2;//(n-2)!/n!
			//ÿ��������������� 
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
