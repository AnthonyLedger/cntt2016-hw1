#include <bits/stdc++.h>

using namespace std;


class UndoHistory {
public:
	int minPresses(vector <string> lines) {
		vector<string>his;
		for(int i=1;i<=lines[0].size();++i)his.push_back(lines[0].substr(0,i));//������ 
		int ret=lines[0].size()+1;
		for(int i=1;i<lines.size();++i){
			size_t mx=lines[i].size()+3;//���㿪ʼ 
			if(lines[i].size()>=lines[i-1].size()&&lines[i].substr(0,lines[i-1].size())==lines[i-1])mx=min(mx,lines[i].size()-lines[i-1].size()+1);
			//ֱ�Ӵ���һ������ 
			for(int j=0;j<his.size();++j)
			if(lines[i].size()>=his[j].size()&&lines[i].substr(0,his[j].size())==his[j])mx=min(mx,lines[i].size()-his[j].size()+3);
			//�ӻ��������� 
			ret+=mx;
			for(int j=1;j<=lines[i].size();++j)his.push_back(lines[i].substr(0,j));
		}
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
