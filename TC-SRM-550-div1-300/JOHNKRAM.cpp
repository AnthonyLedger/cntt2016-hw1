#include<bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
#define N 2500
int a,b,c,d,x,y,z,n,i,j;
bool v[5005][5005];
class RotatingBot
{
    public:
        int minArea(vector <int> moves)
        {
            n=moves.size();
            for(v[N][N]=1;i<n;i++)//ģ��ÿһ��ǰ�� 
            {
                for(j=0;j<moves[i];j++)//ģ��ÿһ�� 
                {
                    if(v[x+dx[z]+N][y+dy[z]+N])return -1;//�ж��Ƿ��ظ��������� 
                    x+=dx[z];
                    y+=dy[z];
                    v[x+N][y+N]=1;
                }
                if(!a&&x<0)a=x;//ȷ��x�½� 
                if(!b&&x>0)b=x;//ȷ��x�Ͻ� 
                if(!c&&y<0)c=y;//ȷ��y�½� 
                if(!d&&y>0)d=y;//ȷ��y�Ͻ� 
                if(x<a||x>b||y<c||y>d||i+1<n&&x+dx[z]>=a&&x+dx[z]<=b&&y+dy[z]>=c&&y+dy[z]<=d&&!v[x+dx[z]+N][y+dy[z]+N])return -1;//�ж��Ƿ�Խ���Ƿ�ת�� 
                z=z+1&3;//ת�� 
            }
            return (b-a+1)*(d-c+1);//����� 
        }
};
