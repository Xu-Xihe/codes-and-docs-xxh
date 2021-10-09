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
int llong(int len){
    int ans=0;
    for (int i = 1; i < len; i++)
    {
        ans+=i;
        //printf("%d\n",ans);
    }
    return ans;
}
int main(){
    while (~scanf("%d",&len))
    {
        if(len==0)return 0;
        lway=llong(len);
        //printf("%d    ljfla=%d\n",len,lway);
        lway*=2;
        for (int i = 1; i <= lway; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            ways[i].end=a;
            ways[i].start=b;
            ways[i++].vale=v;
            ways[i].start=a;
            ways[i].end=b;
            ways[i].vale=v;
        }
        for(int i=0;i<len;i++)fa[i+1]=i+1;
        sort(ways,ways+lway,cmp);
        ans=0;
        for (int i = 0; i < lway; i++)
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