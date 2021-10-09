#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1010;
struct node{
	int x;
	int y;
}node[N];
int fa[N];
bool isOK[N];//1是ok，0是不ok
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int u){
	if(u==fa[u]) return u;
	fa[u]=find(fa[u]);
	return fa[u];
}
void update(int u,int v){
	int fu=find(u);
	int fv=find(v);
	if(fu!=fv)	fa[fu]=fv;
}
int main(){
	int n=0,d=0;
	scanf("%d%d",&n,&d);
    memset(isOK,0,sizeof isOK);
	init(n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&node[i].x,&node[i].y);
		//isOK[i]=0;
	}
	char tmp[10]={};
	while(~scanf("%s",tmp)){
		if(tmp[0]=='O'){
			int id=0;
			scanf("%d",&id);
			if(isOK[id]) continue;
			isOK[id]=1;
			for(int i=1;i<=n;i++){
				if(isOK[i]&&(node[i].x-node[id].x)*(node[i].x-node[id].x)+(node[i].y-node[id].y)*(node[i].y-node[id].y)<=d*d){
					int fi=find(i);
				    int fid=find(id);
                    fa[fi]=fid;
				}
			}				
		}
		else{
			int from=0,to=0;
			scanf("%d%d",&from,&to);
			int ff=find(from);
			int ft=find(to);
			if(ft==ff){
                printf("SUCCESS\n");
                //for(int i=1;i<=n;i++) cout<<isOK[i]<<endl;
            } 
			else{
                printf("FAIL\n");
                //for(int i=1;i<=n;i++) cout<<isOK[i]<<endl;
            }
		}	
	}
	return 0;
}