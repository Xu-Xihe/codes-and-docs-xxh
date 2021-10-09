#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define maxe 1000000
using namespace std;
struct cri
{
    double x,y,z,r;
};
struct way
{
    int start,end;
    double vale;
};
cri in[maxe];
way ways[maxe];
int fa[maxe],lway,len;
double ans;
bool cmp(way a,way b){
    return a.vale<b.vale;
}
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
double far(cri a,cri b,double x,double y){
    double tmp = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))-x-y;
    return tmp>0?tmp:0;
}
int main(){
    while (~scanf("%d",&len))
    {
        if(len==0)return 0;
        ans=0;
        for(int i=0;i<len;i++)fa[i]=i;
        lway=0;
        for (int i = 0; i < len; i++)
        {
            scanf("%lf%lf%lf%lf",&in[i].x,&in[i].y,&in[i].z,&in[i].r);
            for (int j = 0; j < i; j++)
            {
                if (i!=j)
                {
                    ways[lway].start=i;
                    ways[lway].end=j;
                    ways[lway++].vale=far(in[i],in[j],in[i].r,in[j].r);
                }
            }
        }
        sort(ways,ways+lway,cmp);
        for (int i = 0; i < lway; i++)
        {
            //printf("%f-->%f--%f==%llf\n",i,ways[i].start,ways[i].end,ways[i].vale);
            if (find(ways[i].start)!=find(ways[i].end))
            {
                together(ways[i].start,ways[i].end);
                ans+=ways[i].vale;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}