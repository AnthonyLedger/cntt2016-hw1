#include<bits/stdc++.h>
using namespace std;const int MAXN=60;char s[MAXN],s2[MAXN];bool dp[MAXN][MAXN];int cnt[MAXN],cnt2[MAXN];class LittleElephantAndString{public:int getNumber(string A,string B){int n=A.length();for(int i=1;i<=n;i++){s[i]=A[i-1],s2[i]=B[i-1];cnt[s[i]-'A']++,cnt2[s2[i]-'A']++;}for(int i=0;i<26;i++){if(cnt[i]!=cnt2[i])return-1;}for(int i=0;i<=n;i++){memset(dp,0,sizeof dp);dp[0][0]=1;for(int j=0;j<n;j++){for(int k=0;k<=n-i;k++)if(dp[j][k]){dp[j+1][k]=1;if(s[j+1]==s2[i+k+1])dp[j+1][k+1]=1;}}if(dp[n][n-i])return i;}return-1;}} sol ;

int main() { 
		string a = "ABC" ; 
		string b = "CBA"  ;
		printf("%d\n", sol.getNumber(a, b)) ; 
}
