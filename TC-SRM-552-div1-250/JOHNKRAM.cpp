#include<bits/stdc++.h>
using namespace std;
class FoxPaintingBalls
{
    public:
        long long theMax(long long R, long long G, long long B, int N)
        {
            if(N==1)return R+G+B;//N=1���� 
            long long X=(long long)N*(N+1)/6,S=min(min(R,G),B)/X;//X����ÿ��������ÿ����ɫ���ٸ��� 
            if(N%3==1)S=min(S,(R+G+B)/(3*X+1));//N%3==1ʱÿ����������һ����ɫ��һ������һ��ʽ�ӿ��Եó�һ���µĲ���ʽ 
            return S;
        }
};
