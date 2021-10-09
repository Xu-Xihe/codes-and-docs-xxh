#include<cstdio>
#include<algorithm>
#define maxe 100000
struct node
{
    int x,y,k;
}nodes[maxe];
int len,far,ans;
int max_in,in[200][200];
int how_many(int x,int y){
    int ans=0;
    int max_x=x+far,max_y=y+far,min_x=x-far,min_y=y-far;
    for (int i = 0; i < len; i++)
    {
        ans+=nodes[i].x>=min_x&&nodes[i].x<=max_x&&nodes[i].y<=max_y&&nodes[i].y>=min_y?nodes[i].k:0;
    }
    return ans;
}
int main(){
    scanf("%d%d",&far,&len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d%d",&nodes[i].x,&nodes[i].y,&nodes[i].k);
    }
    for (int i = 0; i < 129; i++)
    {
        for (int j = 0; j < 129; j++)
        {
            in[i][j]=how_many(i,j);
            //if(in[i][j]>0)printf("%d-%d->%d\n",i,j,in[i][j]);
            max_in=in[i][j]>max_in?in[i][j]:max_in;
        }
    }
    /*for (int i = 0; i < 128; i++)
    {
        printf("%d ",i);
    }
    printf("\n");*/
    for (int i = 0; i < 129; i++)
    {
        for (int j = 0; j < 129; j++)
        {
            /*if(in[i][j]==max_in){
                ans+=1;
                
            }*/
            ans+=in[i][j]==max_in?1:0;
            //printf("%d ",in[i][j]);
            
        }//printf(" i=%d\n",i);
    }
    printf("%d %d\n",ans,max_in);
    return 0;
}