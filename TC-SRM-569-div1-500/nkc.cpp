#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
struct TheJediTest
{
	int minimumSupervisors(vector <int> students, int K)
	{
		int n=students.size();
		int i,j,x,y;
		int ret=0;
		for(i=0;i<n-1;i++)
		{
			ret+=students[i]/K;
			students[i]%=K;
			//̰�� 
			if(students[i]!=0)
			{
				ret++;
				if(students[i+1]>=K-students[i]) students[i+1]-=K-students[i];//���Ƿ�Ӱ��i+2�� 
				else
				{
					//����i+2���ѧ�� 
					if(i!=n-2&&students[i+2]>=K-students[i]-students[i+1])//
					students[i+2]-=K-students[i]-students[i+1];
					else if(i!=n-2) students[i+2]=0;
					students[i+1]=0;
				}
			}
		}
		ret+=students[n-1]/K;//�������һ�� 
		if(students[n-1]%K!=0) ret++;
		return ret;
	}
};