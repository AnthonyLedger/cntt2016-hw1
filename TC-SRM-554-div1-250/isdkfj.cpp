#include <bits/stdc++.h>

using namespace std;


class TheBrickTowerEasyDivOne {
public:
	int find(int redCount, int redHeight, int blueCount, int blueHeight) {
		if(redHeight==blueHeight)return 2*min(redCount,blueCount)+(redCount!=blueCount);//�߶���� 
		else return 3*min(redCount,blueCount)+(redCount!=blueCount);//�߶Ȳ���ȣ�������� 
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
