#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class HyperKnight {
public:
	long long countCells(int a, int b, int numRows, int numColumns, int k) {
		int r=numRows,c=numColumns;
		LL ret=0;//k=0,1,5,7ʱ���޽� 
		if(a>b)swap(a,b);
		if(k==2)ret=4ll*a*a;//���� 
		else if(k==3)ret=8ll*a*(b-a);//���ϣ�ÿ�������� 
		else if(k==4)ret=4ll*(b-a)*(b-a)+2ll*a*(c-2*b)+2ll*a*(r-2*b);//����+���� 
		else if(k==6)ret=2ll*(b-a)*(r+c-4*b);//���� 
		else if(k==8)ret=1ll*(r-2*b)*(c-2*b);//�м� 
		return ret;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
