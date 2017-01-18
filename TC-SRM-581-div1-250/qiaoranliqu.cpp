#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>

#define N 55

using namespace std;

int A[55][55],cnt[55],i,j,k,sumt[55];
string ans;
class SurveillanceSystem{
	public:
		string getContainerInfo(string s,vector<int> v,int L)
		{
		     int len=s.length();
		     for (i=0;i<v.size();++i) sumt[v[i]]++;
		     
		     for (i=0;i<len;++i) ans+='-';
			 for (i=L-1;i<len;++i) //�����x����Ʒ�Ķ��ж��ٸ� 
			 {
			 	   int st=0;
			 	   for (j=0;j<L;++j) if (s[i-j]=='X') ++st;
				   cnt[st]++;
				   for (j=0;j<L;++j) A[i-j][st]++;
			 }
			 for (i=0;i<len;++i) //ö��ÿ��λ��i,���ǲ��Ǵ���jʹ�����г���Ϊj�Ķ̶�һ������i 
			 	 for (j=0;j<=len;++j)
				  {
				      if (sumt[j]==0) continue;
					  if (cnt[j]-A[i][j]>=sumt[j])
					  {
					  	     if (ans[i]=='-'&&A[i][j]) ans[i]='?';
				      }
				      else ans[i]='+';
				  }
			return ans;
	  }
}FFT;
int main()
{
	vector<int> v; v.push_back(2);
	cout<<FFT.getContainerInfo("-XXXXX-",v,3)<<endl;
}
