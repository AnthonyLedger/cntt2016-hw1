#include <bits/stdc++.h>
/*
	�������ֵ�����С�����е�����
	1.ÿ��Ԫ�����ɾ��a[i]�Σ�����Խ��ɾ���ֵ���ԽС
	2.ÿ��Ԫ�������a[i]�Σ����ң�������ԭ������ǰ���£�Խ�����ֵ���ԽС 
	���Ӷ�O(n) 
*/
using namespace std;

class FoxAndHandle{
	public:
		int n,a[30],used[30];
		int last[60];
		string lexSmallestName(string S){
			string ans = "";
			n = S.size();memset(a,0,sizeof(a));
			for (int i = 0;i < n;i++)
				a[S[i]-'a']++;
			for (int i = 0;i < 26;i++)
				a[i] /= 2;
			for (int i = 0;i < 26;i++)
				used[i] = a[i];
			for (int i = 1;i < n;i++) last[i] = i-1;
			last[0] = -1;
			used[S[0]-'a']--;last[n] = n-1;
			for (int i = 1;i < n;i++) {
				if (used[S[i]-'a'] == 0) {
					last[i+1] = last[i];
					a[S[i]-'a']--;
					continue;	
				}
				while (S[last[i]] > S[i] && a[S[last[i]]-'a'] > 0){
					a[S[last[i]]-'a']--;
					used[S[last[i]]-'a']++;
					last[i] = last[last[i]];
					if (last[i] == -1) break;
				}
				used[S[i]-'a']--;
			}
			int now = n;
			while (now != -1){
				if (now < n){
					if (a[S[now]-'a'] == 0) ans = S[now]+ans;
					else a[S[now]-'a']--;
				}
				now = last[now];
			}
			
			return ans;
		}
};
