#include<bits/stdc++.h>
using namespace std;
bool f[55][2505];
int a[55];
class KingdomAndDice
{
    public:
        double newFairness(vector <int> firstDie, vector <int> secondDie, int X)
        {
            int n=firstDie.size(),N=0,A=0,i,j,k,l;
            sort(secondDie.begin(),secondDie.end());//���� 
            for(i=0;i<n;i++)if(firstDie[i])
            {
                a[j=secondDie.end()-upper_bound(secondDie.begin(),secondDie.end(),firstDie[i])]--;//ͳ�����з�0����p�Ĺ��� 
                A+=j;
            }
            else N++;//ͳ��0�ĸ��� 
            for(i=0;i+1<n;i++)a[n-i-1]=min(N,max(min(secondDie[i+1],X+1)-secondDie[i]-1+a[n-i-1],0));//ͳ��ÿ�ָ��ʿ���������ָ��� 
            a[0]=min(N,max(X-secondDie[i]+a[n-i-1],0));
            f[0][A]=1;
            for(i=0;i<n;i++)for(j=1;a[i];j=min(j<<1,a[i]-=j))for(k=N;k>=j;k--)for(l=n*n;l>=i*j;l--)f[k][l]|=f[k-j][l-i*j];//���ر��� 
            for(i=1;i<=N;i++)for(j=n;j<=n*n;j++)f[i][j]|=f[i-1][j-n];
            for(i=0,j=A;i<=n*n;i++)if(f[N][i]&&max(i*2-n*n,n*n-i*2)<=max(j*2-n*n,n*n-j*2))j=i;//����� 
            return 1-(double)j/n/n;
        }
};
