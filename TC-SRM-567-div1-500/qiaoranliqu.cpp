#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 105
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k;
int A[N][26];
long long a[N],b[N];
class StringGame{
	public:
		vector <int> getWinningStrings(vector <string> S)
		{
				n=S.size();
				vector<int>ans;
				for (i=0;i<n;++i)
					for (j=0;j<S[i].length();++j) A[i][S[i][j]-'a']++;
				for (i=0;i<n;++i) //ö�ٵ�һ����ѡ�ĸ��� 
			{
					memset(a,0,sizeof(a));
					memset(b,0,sizeof(b));
					long long s=1ll<<i;
					for (j=0;j<n;++j) //ö��һ�������� 
					  if (i!=j)
					{
							int cnt=0;
							for (k=0;k<26;++k)
								if (A[i][k]!=A[j][k])
								{
										cnt=1;
										if (A[i][k]>A[j][k]) b[k]|=(1ll<<j);//b[k]��¼����������ַ�����,���Դ����Щ�ַ��� 
										else a[k]|=(1ll<<j); //a[k]��¼����������ַ�����,��Ҫ��Щ�ַ����Ѿ��Ƚϳ���С 
								}
							if (!cnt) break;
					}
					if (j<n) continue;
					for (k=0;k<26;++k) //��ͣ�ؼ�����ԱȽϳ���С���ַ�����. 
					{
							for (j=0;j<26;++j)
								if ((a[j]&s)==a[j]) s|=b[j];
					}
					if (s==((1ll<<n)-1)) ans.pb(i);
			}
			return ans;
		}
};

