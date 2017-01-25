#include <vector>
#include <algorithm>
#define MOD 1000000009
using namespace std;
class UnknownTree{
public:
	struct item{
		int x,y,z;
		bool operator<(const item&v)const{
			if(x!=v.x)return x<v.x;
			if(y!=v.y)return y<v.y;
			return z<v.z;
		}
		bool operator==(const item&v)const{
			return x==v.x&&y==v.y&&z==v.z;
		}
	}items[1000],*iter,V[1000],D[1000];
	void ins(int x,int y,int z){
		if(x>=0&&y>=0&&z>=0&&x+y>0&&y+z>0&&z+x>0)*(iter++)=(item){x,y,z};
	}
	int getCount(vector<int> a, vector<int> b, vector<int> c){
		// ��ɢ��A,B,C��LCA�ľ�����������
		int n=a.size();
		iter=items;
		for(int i=0;i<n;i++){
			ins(a[i],b[i],c[i]); // LCAΪ0~n-1�ĵ�i
			ins(0,b[i]+a[i],c[i]-a[i]); // LCAΪA����i��AB��
			ins(0,b[i]-a[i],c[i]+a[i]); // LCAΪA����i��AC��
			ins(a[i]+b[i],0,c[i]-b[i]); // LCAΪB����i��BA��
			ins(a[i]-b[i],0,c[i]+b[i]); // LCAΪB����i��BC��
			ins(a[i]+c[i],b[i]-c[i],0); // LCAΪC����i��CA��
			ins(a[i]-c[i],b[i]+c[i],0); // LCAΪC����i��CB�� 
		}
		// 0��A������
		ins(0,b[0]-a[0],c[0]-a[0]); // B-A-C
		ins(b[0]-a[0],0,c[0]-b[0]); // A-B-C
		ins(c[0]-a[0],b[0]-c[0],0); // A-C-B
		// 0��B������
		ins(a[0]-b[0],0,c[0]-b[0]);
		ins(a[0]-c[0],c[0]-b[0],0);
		ins(0,a[0]-b[0],c[0]-a[0]);
		// 0��C������
		ins(a[0]-c[0],b[0]-c[0],0);
		ins(0,b[0]-a[0],a[0]-c[0]);
		ins(a[0]-b[0],0,b[0]-c[0]);
		std::sort(items,iter);
		iter=std::unique(items,iter);
		// ��ÿ��������㷽����
		int ans=0;n+=3;
		for(int i=0;i<3;i++)a.push_back(0),b.push_back(0),c.push_back(0);
		for(item*T=items;T<iter;T++){
			bool flag=1; // flag��ʾ�Ƿ�Ϸ� 
			a[n-2]=b[n-3]=T->x+T->y;
			b[n-1]=c[n-2]=T->y+T->z;
			c[n-3]=a[n-1]=T->z+T->x;
			for(int i=0;i<n;i++)D[i]=(item){b[i]-c[i],c[i]-a[i],a[i]-b[i]};
			for(int i=0;i<n;i++){
				int&tp=V[i].x,&dis=V[i].y,&dep=V[i].z; // tp,dis,depΪÿ��������͡���A-B-C���ϵ�λ�á����
				tp=(D[i].x==T->y-T->z)|(D[i].y==T->z-T->x)<<1|(D[i].z==T->x-T->y)<<2;
				if(tp==1||tp==7)dis=T->x-T->y-D[i].z,dep=a[i]+b[i]-T->x-T->y;
				else if(tp==2)dis=T->y-T->z-D[i].x,dep=b[i]+c[i]-T->y-T->z;
				else if(tp==4)dis=T->z-T->x-D[i].y,dep=c[i]+a[i]-T->z-T->x;
				else dis=1; // �޽���� 
				if(dis%2||dep%2||dis<0||dep<0){flag=0;break;}
				dis/=2;dep/=2;
			}
			if(!flag)continue;
			sort(V,V+n);
			int P=1;
			for(int l=0,r=0;l<n&&P;l=r){ // ��ͬһλ�õĵ㹹�� 
				while(r<n&&V[l].x==V[r].x&&V[l].y==V[r].y)r++;
				if(V[l].z||l+1<r&&!V[l+1].z)P=0; // ����ǡ��һ���� 
				else for(int p=l,q=l+1;q<r;q++){
					while(V[p].z<V[q].z)p++;
					P=1ll*P*(p-l)%MOD;
				}
			}
			ans=(ans+P)%MOD;
		}
		return ans; 
	}
};
