#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxe 10000
using namespace std ;
struct ball
{
    int x , y , z;
}balls [maxe];
struct edge
{
    int len,ji[maxe];
}edges[2];
int r , T , len ,h,fa[maxe];
int find(int a){
    return fa[a]==a?a:fa[a]=find(a);
}
void together(int a,int b){
    if(find(a)!=find(b)){
        fa[find(a)]=find(b);
    }
}
int far (ball a,ball b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
void pr(int len ,int ji[]){
    for (int i = 0; i < len; i++)
    {
        printf("%d   ",ji[i]);
    }
    
}
int main(){
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&len,&h,&r);
        if(r*2>=h){
            printf("Yes");
            continue;
        }
        for (int i = 1; i <= len; i++)
        {
            fa[i]=i;
        }
        edges[0].len=0;
        edges[1].len=0;
        for (int i = 1; i <= len; i++)
        {
            scanf("%d%d%d",&balls[i].x,&balls[i].y,&balls[i].z);
            if(balls[i].z+r>=h)edges[1].ji[edges[1].len++]=i;
            if(balls[i].z-r<=0)edges[0].ji[edges[0].len++]=i;
        }
        for (int i = 1; i <= len; i++)
        {
            for (int j = i+1; j <= len; j++)
            {
                if(find(i)!=find(j)&&far(balls[i],balls[j])<=r*r*4){
                    together(i,j);
                }
            }
        }
        int a=false;
        for (int i = 0; i < edges[0].len; i++)
        {
            for (int j = 0; j < edges[1].len; j++)
            {
                if(fa[edges[0].ji[i]]==fa[edges[1].ji[j]]){
                    printf("Yes\n");
                    a=true;
                    break;
                }
            }
            if(a)break;
        }
        if(!a)printf("No\n");
    }
    return 0;
}