#include <bits/stdc++.h>

using namespace std;



class EllysRoomAssignmentsDiv1 {
public:
	double getAverage(vector <string> ratings) {
		vector<int>rat;
		string sb;
		for(int i=0;i<ratings.size();++i)sb+=ratings[i];
		stringstream ss(sb);
		int t;
		while(ss>>t)rat.push_back(t);//ת������ 
		int re=rat[0];
		sort(rat.begin(),rat.end(),greater<int>() );//���� 
		int ri=-1;
		double sum=0;
		for(int i=0;i<rat.size();++i)if(rat[i]==re)ri=i;
		int ro=(rat.size()+19)/20;
		for(int i=0;i<rat.size()/ro;++i){
			if(i==ri/ro)continue;
			for(int j=0;j<ro;++j)if(ro*i+j<rat.size())sum+=rat[ro*i+j];
		}//����Elly�ڵ�����ȫ������ 
		sum/=ro;
		if(rat.size()%ro){//��ʣ�� 
			double sum2=0;
			int R=rat.size()/ro*ro;
			if(ri>=R)return (sum+re)/(rat.size()/ro+1);//Elly������� 
			for(int i=R;i<rat.size();++i)sum2+=rat[i];
			sum2/=(rat.size()-R);			
			return (sum+sum2+re)/(rat.size()/ro+1)/ro*(rat.size()-R)+(sum+re)/(rat.size()/ro)/ro*(ro-rat.size()+R);
			//����������и�û�У����϶�Ӧ�ĸ��� 
		}
		return (sum+re)/(rat.size()/ro);
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
