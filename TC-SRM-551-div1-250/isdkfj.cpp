#include <bits/stdc++.h>

using namespace std;


class ColorfulChocolates {
public:
	int maximumSpread(string chocolates, int maxSwaps) {
		int n=chocolates.size(),ans=1;
		for(int i=0;i<n;++i){//ö������ 
			int l=i-1,r=i+1,sl,sr,res=maxSwaps,cl=1,cr=1,ret=1;
			char ch=chocolates[i];
			while(l>=0&&chocolates[l]!=ch)--l;
			if(l<0)sl=99999;else sl=i-l-1;
			while(r<n&&chocolates[r]!=ch)++r;
			if(r>=n)sr=99999;else sr=r-i-1;//������Ѱ����ͬ��ɫ 
			while(min(sl,sr)<=res){
				if(sl<sr){
					res-=sl;++cl;--l;
					while(l>=0&&chocolates[l]!=ch)--l;//����Ѱ����һ�� 
					if(l<0)sl=99999;else sl=i-l-cl;
				} else {
					res-=sr;++cr;++r;
					while(r<n&&chocolates[r]!=ch)++r;//����Ѱ����һ�� 
					if(r>=n)sr=99999;else sr=r-i-cr;
				}
				++ret;
			}
			ans=max(ans,ret);//���´� 
		}
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
