#include <bits/stdc++.h>

using namespace std;


class KnightCircuit2 {
public:
	int maxSize(int w, int h) {
		if(w>h)swap(w,h);
		if(w==1)return 1;//ֻ��һ��λ�� 
		if(w==2)return (h+1)/2;//�߶�/2��ȡ�� 
		if(w==3&&h==3)return 8;//���� 
		return w*h;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
