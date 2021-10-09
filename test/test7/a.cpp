#include<cstdio>
#define maxe 10000
int who_win[][5]=
{{0,2,1,1,2},
{1,0,2,1,2},
{2,1,0,2,1},
{2,2,1,0,1},
{1,1,2,2,0},};
int len,len_a,len_b,a_in[maxe],b_in[maxe],point_a,point_b;
int main(){
    scanf("%d%d%d",&len,&len_a,&len_b);
    for (int i = 0; i < len_a; i++)
    {
        scanf("%d",&a_in[i]);
    }
    for (int i = 0; i < len_b; i++)
    {
        scanf("%d",&b_in[i]);
    }
    for (int now = 0; now < len; now++)
    {
        int a_id=a_in[now%len_a],b_id=b_in[now%len_b];
        point_a+=who_win[a_id][b_id]==1?1:0;
        point_b+=who_win[a_id][b_id]==2?1:0;
    }
    printf("%d %d\n",point_a,point_b);
    return 0;
}