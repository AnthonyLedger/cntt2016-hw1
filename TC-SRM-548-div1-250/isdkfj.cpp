#include <bits/stdc++.h>

using namespace std;


class KingdomAndTrees {
public:
	int minLevel(vector <int> heights) {
		int n=heights.size();
		int l=0,r=1000000000,mid;
		while(l<r){
			mid=(l+r)>>1;//���ִ� 
			bool flag=1;
			int pre=0;
			for(int i=0;i<n;++i){
				if(heights[i]+mid<=pre){//������ 
					flag=0;
					break;
				}
				pre=max(pre+1,heights[i]-mid);//�õ�ǰ������С 
			}
			//̰���ж��Ƿ���� 
			if(flag)r=mid;else l=mid+1;
		}
		return l;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
