#include <bits/stdc++.h>

using namespace std;

/*
��������һ���ӶΣ���֪��ʼ�߶������Ƕ���
Ȼ����ǰ�����ô���U��֮�����ж�һ���ܷ񵽴�hn����
��Ϊ����˳����û��Ӱ���
*/

struct FoxAndMountainEasy {
	string possible(int, int, int, string);
};

string FoxAndMountainEasy::possible(int n, int h0, int hn, string h) {
	int m = h.length(), i, x = h0;
	for (i=0;i<m;i++)
		if (h[i] == 'U') x++; else
		if (h[i] == 'D') x--;
	int d = x-hn;
	if (d < 0) d = -d;
	if (d > n-m) return "NO";
	if (d % 2 != (n-m) % 2) return "NO";
	int up = (n-m-d)/2;
	if (hn > x) up += hn-x;
	x = h0+up;
	for (i=0;i<m;i++) {
		if (h[i] == 'U') x++; else
		if (h[i] == 'D') x--;
		if (x < 0) return "NO";
	}
	return "YES";
}