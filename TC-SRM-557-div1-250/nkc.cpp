#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<queue>
#include<stack>
using namespace std;
#define MAXN 1010
#define MAXM 1010
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-8
#define ll long long
struct FoxAndMountainEasy
{
	string possible(int n,int sh,int th,string a)
	{
		int i;
		int ch=0;
		for(i=0;i<a.size();i++)
		{
			ch+=a[i]=='U'?1:-1;
		}//����߶ȸñ��� 
		n-=a.size();//��ʣ���ٴλ��� 
		int nd=th-sh-ch;//����Ҫ�ı���� 
		if(n>=abs(nd)&&(((n^abs(nd))&1)^1))
		{//������� 
			sh+=(n-abs(nd))/2;
			if(nd>0)
			{
				int now=sh+nd;//�жϸ߶��Ƿ��Ǹ� 
				for(i=0;i<a.size();i++)
				{
					now+=a[i]=='U'?1:-1;
					if(now<0)
					{
						return "NO";
					}
				}
			}
			else
			{
				int now=sh;
				for(i=0;i<a.size();i++)
				{
					now+=a[i]=='U'?1:-1;
					if(now<0)
					{
						return "NO";
					}
				}
			}
			return "YES";
		}
		return "NO";
	}
};

/*

*/