#include<cstdio>
#define maxe 10005
int len,q_x,q_y;
int in[maxe][4];
bool isin(int t_x,int t_y,int long_x,int long_y,int q_x,int q_y){
    return t_x+long_x>=q_x&&t_y+long_y>=q_y&&q_y>=t_y&&q_x>=t_x?true:false;
}
int main(){
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d%d%d",&in[i][0],&in[i][1],&in[i][2],&in[i][3]);
    }
    scanf("%d%d",&q_x,&q_y);
    for (int i = len-1; i >= 0; i--)
    {
        if(isin(in[i][0],in[i][1],in[i][2],in[i][3],q_x,q_y)){
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}