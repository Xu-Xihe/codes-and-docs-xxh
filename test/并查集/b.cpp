#include<cstdio>
#include<cstring>
#define maxe 1009
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
void together(int a,int b){
	int fx=find(a),fb=find(b);
	if(fx!=fb){
		 fa[fx]=fb;
	}
	return ;
}
int main(){
	while (1)
	{
		scanf("%d",&n);
		if(n==0)return 0;
		memset(ji,0,sizeof(ji));
		for(int i=1;i<=n;i++)fa[i]=i;
		scanf("%d",&m);
		for (int i = 0; i < m; i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			together(a,b);
		}
		//for(int i=1;i<=n;i++)printf("%d-->%d\n",i,fa[i]);
		int ans=0;
		int finder;
		while (1)
		{
			bool is=0;
			for(int i=1;i<=n;i++){
				if (ji[i]==false)
				{
					finder=find(fa[i]);
					is=1;
					break;
				}
			}
			if(!is)break;
			for (int i = 1; i <= n; i++)
			{
				if(find(fa[i])==finder)ji[i]=1;
			}
			ans++;
		}
		printf("%d\n",ans-1);
	}
}