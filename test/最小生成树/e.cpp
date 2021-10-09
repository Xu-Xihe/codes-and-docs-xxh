#include<cstdio>
#include<algorithm>
#define maxe 50000
using namespace std;
struct way
{
    int start,endl,vale;
};
bool cmp(way a,way b){
    return a.vale<b.vale;
}
int len,lway,fa[maxe];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void together(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
    return;
}
way ways[1000000];
int ans;
int main(){
    while(1){
        scanf("%d",&len);
        if(len==0)return 0;
        scanf("%d",&lway);
        ans=0;
        for (int i = 1; i <= lway; i++)
        {
            scanf("%d%d%d",&ways[i].start,&ways[i].endl,&ways[i].vale);
        }
        for(int i=0;i<=len;i++)fa[i]=i;
        sort(ways+1,ways+lway+1,cmp);
        for (int i = 1; i <= lway; i++)
        {
            if (find(ways[i].start)!=find(ways[i].endl))
            {
                together(ways[i].start,ways[i].endl);
                ans+=ways[i].vale;
            }
        }
        printf("%d\n",ans);
    }
}