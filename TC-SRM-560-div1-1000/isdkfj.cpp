#include <bits/stdc++.h>

using namespace std;


class BoundedOptimization {
public:
	double maxValue(vector <string> expr, vector <int> lowerBound, vector <int> upperBound, int maxSum) {
		static bool g[15][15];
		string str;
		for(int i=0;i<expr.size();++i)str+=expr[i];
		for(int i=0;i<str.size();++i){
			if(str[i]=='+')continue;
			g[str[i]-97][str[i+1]-97]=1;
			g[str[i+1]-97][str[i]-97]=1;//��ͼ 
			++i;
		}
		vector<int>lb=lowerBound,ub=upperBound;
		int n=lb.size(),p[15],tot;double v[15],ans=0;
		for(int s=0;s<(1<<n);++s){
			tot=0;
			for(int i=0;i<n;++i)if((s>>i)&1)p[++tot]=i;
			bool flag=1;
			for(int i=1;i<=tot;++i)
				for(int j=i+1;j<=tot;++j)
				if(!g[p[i]][p[j]])flag=0;//�ж��Ƿ����� 
			if(!flag)continue;
			int ss=((1<<n)-1)^s,s2=ss;//ö��ʣ�µ�ȡ�Ͻ绹���½� 
			while(1){
				double res=maxSum;
				for(int i=0;i<n;++i){
					v[i]=0;
					if((s2>>i)&1)v[i]=ub[i];
					else if(!((s>>i)&1))v[i]=lb[i];
					res-=v[i];
				}
				if(res>0){
					double sum=0;
					for(int i=1;i<=tot;++i){
						for(int j=0;j<n;++j)
						if(((ss>>j)&1)&&g[p[i]][j])v[p[i]]+=v[j];//�����ĵ� 
						v[p[i]]+=res/2;
						sum+=v[p[i]];
					}
					double c=res-sum;
					if(tot)c/=tot;//�ڲ����������ճ����������Сֵ 
					bool flag2=1;
					for(int i=1;i<=tot;++i){
						v[p[i]]+=c;
						if(lb[p[i]]-1e-9<=v[p[i]]&&v[p[i]]<=ub[p[i]]+1e-9);//�Ƿ�Ϸ� 
						else flag2=0;
					}
					if(flag2){
						double summ=0;
						for(int i=0;i<n;++i)
							for(int j=i+1;j<n;++j)
							if(g[i][j])summ+=v[i]*v[j];//������ʽ 
						if(summ>ans)ans=summ;//���´� 
					}
				}
				if(s2==0)break;
				s2=(s2-1)&ss;
			}
		}
		return ans;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
