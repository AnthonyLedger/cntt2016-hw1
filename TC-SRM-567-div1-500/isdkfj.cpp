#include <bits/stdc++.h>

using namespace std;

int cnt[55][26];

class StringGame {
public:
	vector <int> getWinningStrings(vector <string> S) {
		vector<int>ret;int len=S[0].size();
		for(int i=0;i<S.size();++i)
			for(int j=0;j<len;++j)++cnt[i][S[i][j]-'a'];//ÿ������ÿ���ַ����ִ��� 
		for(int i=0;i<S.size();++i){
			bool get[55],vis[26];
			int sum=0;
			memset(get,0,sizeof get);
			memset(vis,0,sizeof vis);
			get[i]=1;
			while(sum<S.size()-1){
				int pt=-1;
				for(int j=0;j<26;++j)if(!vis[j]){//��һ��û�Ž�ȥ���ַ� 
					bool flag=1;
					for(int k=0;k<S.size();++k)
					if(!get[k]&&cnt[i][j]<cnt[k][j]){flag=0;break;}//�ַ����������� 
					if(flag){pt=j;break;}
				}
				if(pt==-1)break;
				vis[pt]=1;
				for(int j=0;j<S.size();++j)
				if(!get[j]&&cnt[i][pt]>cnt[j][pt])++sum,get[j]=1;//���ܸɵ��ĸɵ� 
			}
			if(sum==S.size()-1)ret.push_back(i);//ȫ�ɵ��� 
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
