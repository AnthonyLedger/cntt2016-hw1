#include<bits/stdc++.h>
using namespace std;
class KingdomAndTrees
{
    public:
        int minLevel(vector <int> heights)
        {
            int n=heights.size(),l=-1,r=1000000000,m,i,j;
            while(l+1<r)//���ִ� 
            {
                m=l+r>>1;
                for(i=j=0;i<n;i++) if(j<heights[i])j=max(j+1,heights[i]-m);//�ж� 
                else if(j+1>heights[i]+m)break;
                else j++;
                if(i==n)r=m;
                else l=m;
            }
            return r;
        }
};
