#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
int n,m,i,j,p[100005];
bool b[1000005];
ll work(ll X,int x)//����[1,X]���ж��ٸ��������õ�[x+1,m]�������������η���˱�ʾ 
{
    if(x==m||p[x]>X)return 1;//�߽���� 
    if((ll)p[x]*p[x+1]>X)return upper_bound(p+x,p+m,X)-p-x+1;//��֦ 
    ll s=work(X,x+1);//��x+1������û�г��� 
    for(X/=p[x];X;X=X/p[x]/p[x])s+=work(X,x+1);//��x+1������������ 
    return s;
}
class HolyNumbers
{
    public:
        long long count(long long upTo, int maximalPrime)
        {
            N=upTo;
            n=maximalPrime;
            for(i=2;i*i<=n;i++)if(!b[i])for(p[m++]=i,j=i*i;j<=n;j+=i)b[j]=1;//������ɫ��ɸ��Ԥ�������� 
            for(;i<=n;i++)if(!b[i])p[m++]=i;
            return work(N,0);
        }
};
