#include<cstdio>
#include<cstring>
#include<math.h>
#define maxe 1009
using namespace std;
int fa[maxe],n,d;
bool is[maxe];
struct copu
{
    int x,y;
};
copu in[maxe];
int far(copu a,copu b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
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
    if (fx!=fy)
    {
        fa[fx]=fy;
    }
    return ;
}
int main(){
    scanf("%d%d",&n,&d);
    d*=d;
    for(int i=1;i<=n;i++)fa[i]=i;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&in[i+1].x,&in[i+1].y);
    }
    char a[10];
    while (~scanf("%s",a))
    {
        int first,endl;
        if(a[0]=='S'){
            scanf("%d%d",&first,&endl);
            if(find(first)==find(endl))printf("SUCCESS\n");
            else printf("FAIL\n");
        }
        else{
            scanf("%d",&first);
            if(is[first])continue;
            is[first]=true;
            for (int i = 1; i <= n; i++)
            {
                if (i!=first&&far(in[i],in[first])<=d&&is[i])
                {
                    together(i,first);
                }
            }
            //for(int i=0;i<n;i++)printf("%d-->%d\n",i+1,fa[i+1]);
        }
    }
    return 0;
}