#include <vector>
#include <string>
#include <cstring>
#define U 100000
#define P(x,y) ((x)*m+(y)+2)
using namespace std;
class BoardPainting{
public:
	struct edge{int to,cap;edge*rev,*next;}E[100000],*ne,*first[2510],*cur[2510];
	void link(int a,int b,int c){
		*ne=(edge){b,c,ne+1,first[a]};first[a]=ne++;
		*ne=(edge){a,0,ne-1,first[b]};first[b]=ne++;
	}
	int Q[2510],D[2510];
	int dfs(int i,int c){
		if(i==1||!c)return c;
		int flow=0,f;
		for(edge*&e=cur[i];e;e=e->next)if(e->cap&&D[e->to]==D[i]-1&&(f=dfs(e->to,c<e->cap?c:e->cap))){
			flow+=f;e->cap-=f;e->rev->cap+=f;
			if(!(c-=f))return flow;
		}
		return flow;
	}
	int maxflow(){
		for(int f=0;;){
			memset(D,0,sizeof(D));
			memcpy(cur,first,sizeof(cur));
			for(int head=0,tail=Q[0]=D[1]=1;head<tail;head++)
				for(edge*e=first[Q[head]];e;e=e->next)
					if(e->rev->cap&&!D[e->to])D[Q[tail++]=e->to]=D[Q[head]]+1;
			if(!D[0])return f;
			f+=dfs(0,1<<30);
		}
	}
	int minimalSteps(vector <string> target){
		ne=E;memset(first,0,sizeof(first));
		int n=target.size(),m=target[0].length(),s=0;
		bool u,d,l,r;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)if(target[i][j]=='#'){
				u=i&&target[i-1][j]=='#';d=i<n-1&&target[i+1][j]=='#';
				l=j&&target[i][j-1]=='#';r=j<m-1&&target[i][j+1]=='#';
				// ��0��ʾ����V�������²�ͬ�ĸ�����1����
				link(0,P(i,j),U+!u+!d);
				if(u)link(P(i-1,j),P(i,j),1);
				if(d)link(P(i+1,j),P(i,j),1);
				// ��1��ʾ����H�������Ҳ�ͬ�ĸ�����1����
				link(P(i,j),1,U+!l+!r);
				if(l)link(P(i,j),P(i,j-1),1);
				if(r)link(P(i,j),P(i,j+1),1);
				s++;
			}
		}
		return (maxflow()-U*s)/2; // ��=�˵���/2
	}
};

		return (maxflow()-U*s)/2; // ��=�˵���/2
	}
};
;
	}
};
��ǵ�һ�����в��ʱתΪL->D
				else if(ty==C-1)sx==tx?is_line[sx]=1:left_in[sx]=right_out[tx]=1; // L->R��������ͬһ��
				else if(!tx)ans++,left_out[sx]=1; // L->U��תΪU->L
				else left_in[sx]=1; // L->D
			}
			else if(sy==C-1){
				if(!ty)right_in[sx]=left_out[tx]=1; // R->L
				else if(ty==C-1)right_in[sx]=1,!sx||tx>sx+1?right_out[tx]=1:1; // R->R���ǵ�һ�����в��ʱתΪR->D
				else right_in[sx]=1; // R->D
			}
			else if(!sx){
				ans++;
				if(!ty)left_out[tx]=1; // U->L
				else if(ty==C-1)right_out[tx]=1; // U->R
			}
			else if(!ty)left_in[tx]=1; // D->L��תΪL->D
			else if(ty==C-1)right_in[tx]=1; // D->R��תΪR->D
		}
		return ans+dfs(0,R,0,0);
	}
};
1; // D->R��תΪR->D
		}
		return ans+dfs(0,R,0,0);
	}
};
j),type[j]=find_val(j),select[j]=0;
		init(labels.size());link(0,labels.size(),0);
		return dfs2(0)?"POSSIBLE":"IMPOSSIBLE"; // 搜索2
	}
};
1ll*P*(p-l)%MOD;
				}
			}
			ans=(ans+P)%MOD;
		}
		return ans; 
	}
};

			for(edge*e=first[i];e;e=e->next){
				if(siz[e->to]==n-k)dfs2(e->to,i,dep+1,ff*fv[e->to]%MOD);
			}
		}
		else for(edge*e=first[i];e;e=e->next)
			if(e->to!=fa)dfs2(e->to,i,dep+1,ff);
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
