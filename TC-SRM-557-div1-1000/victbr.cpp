/*
���Ǹ�˹��Ԫ��ӵ�λ����λ���𰸾���
��Ȼ������һ��������Ԫ�����Ž��е�ǰλ��һ��ֻ��1��0��
���ǻ�ԭ�Ĺ���ȷ���� 
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class XorAndSum{
	public:
		int n;
		long long maxSum(vector<long long> number){
			n = number.size();
			int p = 0;
			for (int i = 50;i >= 0;i--){
				ll u = 1;u <<= i;int k = -1;
				for (int j = p;j < n;j++)
					if (u & number[j]) {k = j;break;}
				if (k != -1){
					swap(number[k],number[p]);
					for (int j = 0;j < n;j++)
						if (p != j && (number[j] & u)) number[j] ^= number[p];
					p++;
				}
			}
			for (int i = 1;i < n;i++) number[0] ^= number[i];
			for (int i = 1;i < n;i++) number[i] ^= number[0];
			for (int i = 1;i < n;i++) number[0] += number[i];
			return number[0];
		}
}A;
