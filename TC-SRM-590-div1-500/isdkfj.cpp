#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL a[55];

class XorCards {
public:
	long long numberOfWays(vector<long long> number, long long limit) {
		int n=0;
		for(int d=60;d>=0;--d){
			int p=-1;
			for(int i=0;i<number.size();++i)
				if((number[i]>>d)&1){p=i;break;}//��λΪ1 
			if(p==-1)continue;
			++n;a[n]=number[p];
			for(int i=1;i<n;++i)if((a[i]>>d)&1)a[i]^=a[n];//����֮ǰ�� 
			for(int i=0;i<number.size();++i)
				if((number[i]>>d)&1)number[i]^=a[n];//������λΪ1�� 
		}//�����Ի� 
		LL tmp=0,ans=0;
		for(int i=1;i<=n;++i)
		if((tmp^a[i])>limit)ans+=1ll<<(n-i);//��limit�� 
		else tmp^=a[i];
		ans=(1ll<<number.size())-(ans<<(number.size()-n));//�󷽰��� 
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
