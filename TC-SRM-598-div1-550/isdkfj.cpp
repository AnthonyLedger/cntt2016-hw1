#include <bits/stdc++.h>

using namespace std;


class FoxAndFencing {
public:
	string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
		if(d-mov1<=rng1)return "Ciel";//һ���ܸɵ� 
		if(d+mov1-mov2<=rng2)return "Liss";//��һ��Ҳ���� 
		if(mov1>mov2){
			if(mov2+rng2+1+mov2-mov1<=rng1)return "Ciel";//�ߵ�����Ĳ����ɵ��ĵط� 
			return "Draw";
		}else if(mov1<mov2){
			if(mov1+rng1+1+mov1-mov2<=rng2)return "Liss";//�ߵ�����Ĳ����ɵ��ĵط� 
			return "Draw";
		}else return "Draw";//˭������˭ 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
