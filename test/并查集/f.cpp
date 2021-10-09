#include<cstdio>
#include<cstring>
#include <set>
#define maxe 50009
using namespace std;
int fa[maxe],n,m;
bool ji[maxe];
int find(int x){
	if (fa[x]==x)
	{
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void together(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
	return;
}
int main(){
	for (int zz=1;;zz++)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)return 0;
		memset(ji,0,sizeof(ji));
		for(int i=1;i<=n;i++)fa[i]=i;
		for (int i = 0; i < m; i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			together(a,b);
		}
		std::set<int> s;
		for(int i = 1;i<=n;i++){
			s.insert(find(i));
		}
		printf("Case %d: %d\n",zz,s.size());
	}
}