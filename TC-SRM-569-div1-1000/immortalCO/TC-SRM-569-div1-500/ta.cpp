#include<bits/stdc++.h>
using namespace std;
const int N=20+5;
class TheJediTest
{
	public:
		int minimumSupervisors(vector <int> students,int k)
		{
			int a[N]={0};
			//a[i]��ʾ��i���ж��������Ե�i-1��� 
			int ans=0;
			for(int i=0,tmp;i<students.size();++i)
			{
				ans+=(a[i]+students[i])/k;
				
				if(tmp=(a[i]+students[i])%k)//�����ǰ��i�����������k�ı��� 
					if(i+1<students.size())//������������ĵ�i+1�� 
						if(tmp<=students[i])a[i+1]=tmp;//�����i����������԰Ѷ�������ⲿ���ӵ���һ��Ļ� 
						else//�õ�i+1����˾���������i�� 
						{
							students[i+1]-=min(students[i+1],k-tmp);
							++ans;
						}
					else ++ans;//����Ѿ�û��i+1��Ļ�����������ⲿ�־�ֻ�����������ˣ� 
			}
			
			return ans;
		}
};
