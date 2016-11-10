#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Mod=1e9+9;
const LL inf=(1ULL<<63)-1;
const int K=16+3,B=10+3;
LL coe1[K][K],coe2[K][K],coe3[K][K],tmp[K][K];
//coe1�����������ľ��� coe2��������p^tת�Ƶ�p^{t+1}��coe3�Ǵ𰸾��� 
inline void merge(LL a[K][K],LL b[K][K],int k)//����� 
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<=k;++i)
		for(int j=i;j<=k;++j)
			if(a[i][j])
				for(int o=j;o<=k;++o)
					if(b[j][o])
						(tmp[i][o]+=a[i][j]*b[j][o])%=Mod;
	memcpy(b,tmp,sizeof(tmp));
}
inline void init(LL a[K][K],int k)//����һ����λ���� 
{
	memset(a,0,sizeof(tmp));
	for(int i=k;i>=0;--i)a[i][i]=1;
}
class MegaFactorial
{
	public:
		inline int countTrailingZeros(int n,int k,int b)
		{
			//�ҵ�b������������dvs���Լ�����ָ��ind 
			int prm[4]={2,3,5,7};
			int dvs,ind=0;
			for(int i=4;i--;)
				if(b%prm[i]==0)
				{
					dvs=prm[i];
					while(b%dvs==0)++ind,b/=dvs;
					break;
				}
			Mod*=ind;
			
			//��ʼ������ 
			coe1[0][0]=1;
			for(int i=1;i<=k;++i)
				for(int j=i;j<=k;++j)
					coe1[i][j]=1;
			init(coe3,k);
			for(;n;n/=dvs)
			{
				//���� 
				int dx=dvs,dn=n%dvs;
				init(coe2,k);
				for(;dn||dx;dn>>=1,dx>>=1)
				{
					if(dx&1)merge(coe1,coe2,k);
					if(dn&1)merge(coe1,coe3,k);
					merge(coe1,coe1,k);
				}
				memcpy(coe1,coe2,sizeof(coe1));
				for(int i=k;i;--i)(++coe1[0][i])%=Mod;//�����Ա�ʾ�ĳ�����+1 
			}
			LL ans=(coe3[0][k]+Mod)%Mod/ind;
			return ans;
		}
};
