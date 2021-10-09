#include<cstdio>
#include<iostream>
#define maxe 30009
using namespace std;
int fa[maxe],in[maxe],n,m;
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
	while(cin>>n>>m){
		if(n==0&&m==0)return 0;
		for(int i=0;i<n;i++)fa[i]=i;
		for (int i = 0; i < m; i++)
		{
			int len;
			scanf("%d",&len);
			for (int j = 0; j < len; j++)
			{
				scanf("%d",&in[j]);
			}
			for (int j = 1; j < len; j++)
			{
				together(in[j-1],in[j]);
			}
		}
		int finder=find(fa[0]);
		int ans=0;
		for (int i = 0; i < n; i++)
		{
			if(find(fa[i])==finder)ans++;
		}
		printf("%d\n",ans);
	}
}