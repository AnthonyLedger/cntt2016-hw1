/*
ÿ��״̬��Կ�������ǹ̶��ģ���ʵ����ȼ��ڿ��е�״̬�ж�һ����Ϣ�����ֵ��ֻҪ�����Щ״̬���м��ɡ�
��Ȼ����ɫԽ�࣬Խ���׿��С� ����ö��һ����ɫ����󻯰�ɫ����һ����ɫ��ȷ���ˡ� 
*/
#include <bits/stdc++.h>

using namespace std;
const int M = 4096+10,N = 130+10;

class KeyDungeonDiv1{
	public:
		int f[M][N],sum[M],n,ans;
		int maxKeys(vector<int> dr,vector<int> dg,vector<int> rr,vector<int> rg,vector<int> rw,vector<int> keys){
			memset(f,-1,sizeof(f));
			f[0][keys[0]] = keys[2];
			n = dr.size();
			sum[0] = keys[0]+keys[1]+keys[2];
			for (int i = 1;i < (1<<n);i++){
				for (int j = 0;j < n;j++){
					int u = (1<<j);
					if (u&i) {
						sum[i] = sum[i-u];
						sum[i] -= dg[j]+dr[j];
						sum[i] += rr[j]+rg[j]+rw[j];
						break;
					}
				}
			}
			ans = sum[0];
			for (int i = 1;i < (1<<n);i++){
				int tot = 0;
				for (int j = 0;j < n;j++) if ((1<<j)&i) tot++;
				for (int j = 0;j < n;j++){
					int u = (1<<j);
					if (!(i&u)) continue;
					for (int k = 0;k <= tot*10;k++){
						if (f[i-u][k] < 0) continue;
						int rrr = k,www = f[i-u][k],ggg = sum[i-u]-rrr-www;//��Ҫ���1 
						if (ggg < 0) continue;
						if (dr[j] <= rrr) rrr -= dr[j];
						else {www -= dr[j]-rrr;rrr = 0;}
						if (dg[j] <= ggg) ggg -= dg[j];
						else {www -= dg[j]-ggg;ggg = 0;}						
						if (www < 0) continue;
						rrr += rr[j];www += rw[j];ggg += rg[j];
						f[i][rrr] = max(f[i][rrr],www);
						ans = max(ans,rrr+www+ggg);
					}
				}
			}
			return ans;
		}
};
