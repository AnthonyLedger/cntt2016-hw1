#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


class BigFatInteger{
	public:
		int ans,cnt;
		int minOperations(int A, int B){
			int u = (int)sqrt(A);
			for (int i = 2;i <= u+1;i++){
				if (A%i == 0) cnt++;else continue;//i����������ʱҪ���� 
				ll v = 0,z = 1;
				int tot = 0;
				while (A%i == 0){
					v++;A /= i;
				}
				v *= B;
				while (z+z <= v){
					tot++;z <<= 1;
				}
				if (z != v) tot++;
				ans = max(ans,tot);
			}
			if (A != 1){//ע��Ҫ�������һ�������� 
				cnt++;
				ll v = B,z = 1;
				int tot = 0;
				while (z+z <= v){
					tot++;z <<= 1;
				}
				if (z != v) tot++;
				ans = max(ans,tot);				
			}
			return ans+cnt;
		}
};
