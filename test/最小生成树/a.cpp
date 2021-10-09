#include<cstdio>
#include<algorithm>
using namespace std;
struct way
{
    int start,endl,vale;
};
bool cmp(way a,way b){
    return a.vale<b.vale;
}
int len,lway,fa[100];
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
way ways[100];
int ans;
int main(){
    while(1){
        scanf("%d",&len);
        if(len==0)return 0;
        lway=0;
        ans=0;
        for (int i = 0; i < (len-1); i++)
        {
            char a;
            int llen;
            scanf("\n%c %d",&a,&llen);
            for (int j = 0; j < llen; j++)
            {
                char fi;
                scanf(" %c%d",&fi,&ways[lway].vale);
                ways[lway].start=a-'A';
                ways[lway].endl=fi-'A';
                lway++;
            }
        }
        for(int i=0;i<len;i++)fa[i]=i;
        sort(ways,ways+lway,cmp);
        for (int i = 0; i < lway; i++)
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