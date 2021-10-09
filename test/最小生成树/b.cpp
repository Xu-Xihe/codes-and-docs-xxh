#include<cstdio>
#include<algorithm>
using namespace std;
struct way
{
    int start,end,vale;
};
way ways[50000];
int len,ans,lway,fa[50000];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void together(int x,int y){
    int fx=find(x),fy=find(y);
    if (fx!=fy)
    {
        fa[fx]=fy;
    }
    return ;
}
bool cmp(way a,way b){
    return a.vale<b.vale;
}
int main(){
    while (~scanf("%d",&len))
    {
        ans=0;
        lway=0;
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j <= len; j++)
            {
                int a;
                scanf("%d",&a);
                if (i!=j)   
                {
                    ways[lway].start=i;
                    ways[lway].end=j;
                    ways[lway].vale=a;
                    lway++;
                }
            }
        }
        for(int i=0;i<len;i++)fa[i+1]=i+1;
        int llen;
        scanf("%d",&llen);
        for (int i = 0; i < llen; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            together(a,b);
        }
        sort(ways,ways+lway,cmp);
        for (int i = 0; i < lway-llen; i++)
        {
            if (find(ways[i].start)!=find(ways[i].end))
            {
                together(ways[i].start,ways[i].end);
                ans+=ways[i].vale;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}