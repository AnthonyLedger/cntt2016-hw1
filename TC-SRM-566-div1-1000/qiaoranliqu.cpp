#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>

#define N 255

#define Mo 100007

using namespace std;

const double pi=acos(-1.0);

struct Point{
  double x,y;
}A[N],B[N];

void jia(int &x,int y) { x+=y; if (x>=Mo) x-=Mo; }

double cross(Point a,Point b,Point c)
{
   return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int F[N][N],G[2][N],n,m,i,sum[N],al[N][N],can[N][N],cc[N],j,k,col[N];

char c[5];

double r;

class FencingPenguins{
	public:
		int countWays(int n,int rc,vector<int> xx,vector<int> yy,string s)
{
   m=xx.size();
   r=rc;
   for (i=0;i<n;++i) A[i]=(Point){r*cos(2.*pi*i/n),r*sin(2.*pi*i/n)}; //��ÿ���㶼�ȱ�ʾ����. 
   for (i=0;i<m;++i) 
   {
   	   col[i]=s[i]-'A';
   	   sum[col[i]]++;
   	   B[i]=(Point){xx[i],yy[i]};
   }
   for (i=0;i<n;++i)
     for (j=i+1;j<n;++j) //Ԥ�������ֱ��(i,j)������ʱ����ж��ٵ��Լ���ɫ 
     { 
            memset(cc,0,sizeof(cc));
            for (k=0;k<m;++k)
              if (cross(A[i],A[j],B[k])<=0) 
              {
              	   al[i][j]++;
              	   cc[col[k]]++;
               }
             for (k=0;k<100;++k)
                if (cc[k]&&cc[k]!=sum[k]) can[i][j]=1;
             if (j-i==1&&al[i][j]) return 0;
     }
    memset(cc,0,sizeof(cc));
    i=n-1; j=0; //����(n-1,0)������Խ��ֱ��ҲҪ������һ�� 
            for (k=0;k<m;++k)
              if (cross(A[i],A[j],B[k])<=0) 
              {
              	   al[i][j]++;
              	   cc[col[k]]++;
               }
             for (k=0;k<100;++k)
                if (cc[k]&&cc[k]!=sum[k]) can[i][j]=1;
             if (al[i][j]) return 0;
   for (i=n-1;i>=0;--i) //��F_{i,j}Ϊ[i,j]�ⲿ�ֶ����Ϸ��ķ���,��G_{i,j,x}Ϊ[i,j]��������͹����һ��͹��,����(i,j)Ϊ͹�ǵ������˵��ҷ��Ϻ��Ƿ�Ϸ��Ĵ� 
   {
          memset(G,0,sizeof(G)); //�˴�G������ά,��Ϊ���ǽ��õ�iʱ����Ϣ 
          F[i][i]=F[i+1][i]=F[i][i+1]=G[0][i+1]=1;
          for (j=i+2;j<n;++j)
          {
          		if (al[i][j]==al[i+1][j]) jia(F[i][j],F[i+1][j]);//���û�ж���ĵ�,F�ı߽������չһά 
          		if (!can[i][j]&&al[i+1][j-1]==al[i][j]) jia(G[0][j],F[i+1][j-1]); //��������һ���������͹�� 
          		for (k=i+1;k<j;++k) if (al[k][j]==al[k+1][j-1]&&!can[k][j]) //����F������G 
          		{
          		        if (al[i][j]!=al[i][k]+al[k][j])
          				jia(G[1][j],1ll*G[0][k]*F[k+1][j-1]%Mo);
          				else jia(G[0][j],1ll*G[0][k]*F[k+1][j-1]%Mo);
          				jia(G[1][j],1ll*G[1][k]*F[k+1][j-1]%Mo);
          		}
          		for (k=i+1;k<=j;++k) if (al[i][j]==al[i][k]+al[k+1][j]&&!can[i][k]) //ö�ٱ����С��һ��͹�ǵ�λ�� 
          		 jia(F[i][j],1ll*G[1][k]*F[k+1][j]%Mo);
          }
   }
   return F[0][n-1];
  }
}ETT;

int main()
{
	  string s="Y"; 
	  vector<int> x,y; x.push_back(5); y.push_back(-5);
	  printf("%d\n",ETT.countWays(3,10,x,y,s));
}
