#include <vector>
#include <string>
#define MOD 1000000009
using namespace std;
class TheExperiment{
public:
	int a[310],l[310],r[310],t[310]; // a[i]Ϊǰi�����ĺͣ�[l[i],r[i])Ϊ�����i~j-1�����ĺ���[A,B]����j-i<L��j�����䣬t[i]��ʾi֮���L�����ĺ��Ƿ���[A,B]��
	long long f[310][310][3]; // f[i][j][k]Ϊ��[l,n)��ȡ��j������(l>=i)��[0,l)״̬Ϊk��k=0:��;k=1:��������L������;k=2:��L�����䣩�ķ�������
	int countPlacements(vector <string> intensity, int M, int L, int A, int B){
		int n=0;
		for(int i=0;i<intensity.size();i++)
			for(int j=0;j<intensity[i].length();j++)a[++n]=intensity[i][j]-'0';
		for(int i=0;i<n;i++)a[i+1]+=a[i];
		// Ԥ��������
		for(int i=0;i<n;i++){
			while(l[i]<=n&&a[l[i]]-a[i]<A)l[i]++;
			while(r[i]<=n&&a[r[i]]-a[i]<=B)r[i]++;
			l[i+1]=l[i];r[i+1]=r[i];
		}
		for(int i=0;i<n;i++){
			if(l[i]>i+L)r[i]=l[i]; // i~i+L-1�ĺͲ���A���޷�ת��
			else if(i+L<r[i])r[i]=i+L,t[i]=1; // ����L���������[A,B]�ڣ��޸�����
		}
		// ת��(i,j,k)
		// 1:��ѡi��ת�Ƶ�(i+1,j,0)��ǰ����k��Ϊ1
		// 2:��һ�����串��i��ת�Ƶ�(i',j-1,k')����i'-i=Lʱk'=2������k'=1
		long long g[2];
		f[n][0][0]=f[n][0][2]=1;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<=M;j++){
				for(int k=0;k<2;k++)g[k]=j?(f[l[i]][j-1][k+1]+MOD-f[r[i]][j-1][k+1]+(t[i]?f[i+L][j-1][2]+MOD-f[i+L+1][j-1][2]:0))%MOD:0; // ת��2�ķ�����
				f[i][j][0]=(f[i+1][j][0]*2+MOD-f[i+2][j][0]+g[0])%MOD;
				f[i][j][1]=(f[i+1][j][1]+g[0])%MOD;
				f[i][j][2]=(f[i+1][j][2]+f[i+1][j][0]+MOD-f[i+2][j][0]+g[1])%MOD;
			}
		}
		return (f[0][M][0]+MOD-f[1][M][0])%MOD;
	}
};
