// WAonSystemTest
#include <vector>
#include <string>
using namespace std;
class TPS{
public:
	int N,up[55],down[55],f[55]; // up[i]:i�Ϸ��Ƿ�Ϊ�� down[i]:i�·��Ƿ�Ϊ�� f[i]:i�ĸ��߱�ȡ�������i��������ȡ���ٸ���
	vector<int> to[55],ch[55]; // to[i]:i�ĳ��� ch[i]:i���ӽڵ�
	void cmin(int&a,int b){b<a?a=b:1;}
	void init(int i,int fa){ // Ԥ����up��ch
		for(int e=0,j;e<to[i].size();e++)
			if((j=to[i][e])!=fa)ch[i].push_back(j),init(j,i);
		down[i]=!ch[i].size()||ch[i].size()==1&&down[ch[i][0]];
	}
	void dfs(int i){ // ����down��f
		for(int c=0,j;c<ch[i].size();c++){
			j=ch[i][c];
			if(i)up[j]=up[i]&&ch[i].size()==1;
			else up[j]=ch[i].size()==1||ch[i].size()==2&&down[ch[i][!c]];
			dfs(j);
		}
		if(down[i]){f[i]=1;return;}
		f[i]=1<<30;
		// ���i����i���1��������ѡ���ұ�������
		int fmax=0,fsum=0;
		for(int c=0;c<ch[i].size();fsum+=f[ch[i][c++]])if(down[ch[i][c]])cmin(fmax,-f[ch[i][c]]);
		cmin(f[i],fsum+(ch[i].size()<1)); // ����������ѡ
		cmin(f[i],fsum+fmax+(ch[i].size()<2)); // 1��������ѡ
	}
	int minimalBeacons(vector <string> linked){
		if((N=linked.size())==1)return 0;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(linked[i][j]=='Y')to[i].push_back(j);
		init(0,-1);dfs(0);
		int ans=1<<30;
		for(int i=1;i<N;i++)if(up[i]){ // ö�����ĸ�i��i��ÿ������������ȡ
			// ���i��ѡ��Ҫ������2������
			int sum=ch[i].size()<2;
			for(int c=0;c<ch[i].size();c++)sum+=f[ch[i][c]];
			cmin(ans,sum);
		}
		// ��Ϊ0�����һ��������ѡ���ұ������� 
		int sum=0,fmax=0;
		for(int c=0;c<ch[0].size();sum+=f[ch[0][c++]])if(down[ch[0][c]])cmin(fmax,-f[ch[0][c]]);
		cmin(ans,sum+(ch[0].size()<2));
		cmin(ans,sum+fmax+(ch[0].size()<3));
		return ans;
	}
};
fmax+(ch[0].size()<3));
		return ans;
	}
};
fo[i][j])==' '?add(s),l=0:s[l++]=x;
		add(s);
		return solver.solve();
	}
};
es[y][2]);
			}
		}
		return ans;
	}
};
ej=first[E[j].to];ej;ej=ej->next)if(!ej->del&&ej!=E[j].rev)solver.w[solver.nx][solver.ny++]=f[ei->to][ej-E];
			solver.nx++;
		}
		f[i][j]+=solver.match();
	}
	int getmax(vector <int> a, vector <int> b){
		N=a.size()+1;ne=E;
		for(int i=0;i<N-1;i++)link(a[i],b[i]);
		now=0;dfs(0,-1);
		int ans=0,tmp;
		for(int i=1;i<N;i++){
			fe[i]->del=fe[i]->rev->del=1;
			memset(f,0,sizeof(f));
			for(int j=0;j<N;j++)if(pre[j]<pre[i]||pre[j]>=pos[i]){
				for(edge*ei=first[i];ei;ei=ei->next)if(!ei->del)
					for(edge*ej=first[j];ej;ej=ej->next)if(!ej->del)calc(ei->to,ej-E);
				solver.nx=0;
				for(edge*ei=first[i];ei;ei=ei->next)if(!ei->del){
					solver.ny=0;
					for(edge*ej=first[j];ej;ej=ej->next)if(!ej->del)solver.w[solver.nx][solver.ny++]=f[ei->to][ej-E];
					solver.nx++;
				}
				if((tmp=1+solver.match())>ans)ans=tmp;
			}
			fe[i]->del=fe[i]->rev->del=0;
		}
		return ans;
	}
};
ver.match())>ans)ans=tmp;
			}
			fe[i]->del=fe[i]->rev->del=0;
		}
		return ans;
	}
};
ep+1,ff);
	}
	int getCount(vector <int> edge1, vector <int> edge2, int k){
		this->n=edge1.size()+1;this->k=k;ne=E;ans=0;
		for(int i=0;i<edge1.size();i++)link(edge1[i],edge2[i]),link(edge2[i],edge1[i]);
		init();
		if(k==1)return fac[n];
		if(2*k>n){
			init(0,-1);
			dfs1(0,-1,1);
			return ans*fac[2*k-n]%MOD*fac[n-k]%MOD*fac[n-k]%MOD;
		}
		for(int i=0;i<n;i++){
			init(i,-1);
			dfs2(i,-1,0,inv[k]);
		}
		return ans*fac[k]%MOD*fac[k]%MOD;
	}
};
