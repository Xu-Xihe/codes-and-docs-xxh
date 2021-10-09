#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define maxe 1000000
using namespace std;
struct zuo
{
    int x,y;
};
struct way
{
    int start,end,vale;
};
way ways[5000000];
int fa[maxe],lway,llway,ci,len;
zuo dian[maxe];
int ji[maxe],jil;
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
int far(int ax,int bx,int ay,int by){
    return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}
int main(){
    scanf("%d",&ci);
    while (ci--)
    {
        scanf("%d%d",&llway,&len);
        if(llway==0)llway++;
        lway=0;
        for (int i = 0; i < len; i++)
        {
            scanf("%d%d",&dian[i].x,&dian[i].y);
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i!=j)
                {
                    ways[lway].start=i;
                    ways[lway].end=j;
                    ways[lway].vale=far(dian[i].x,dian[j].x,dian[i].y,dian[j].y);
                    lway++;
                }
            }
        }
        for(int i=0;i<lway;i++)fa[i]=i;
        memset(ji,0,sizeof(ji));
        jil=0;
        sort(ways,ways+lway,cmp);
        for (int i = 0; i < lway; i++)
        {
            //printf("%d-->%d--%d==%d\n",i,ways[i].start,ways[i].end,ways[i].vale);
            if (find(ways[i].start)!=find(ways[i].end))
            {
                together(ways[i].start,ways[i].end);
                ji[jil++]=ways[i].vale;
            }
        }
        /* *for (int i = 0; i < jil; i++)
        {
            printf("%d--->%d\n",i,ji[i]);
        }
        */
        //printf("%d-----%d--------%d------%d\n",jil,llway,jil-llway,ji[jil-llway]);
        //printf("%d      ",sqrt(ji[jil-llway-1]));
        printf("%.2f\n",sqrt(ji[jil-llway]*1.0));
    }
    return 0;
}