#include<cstdio>
#include<algorithm>
int n,now_y,now_x;
int ans[50][50];
int main(){
    scanf("%d",&n);
    now_y=n/2;
    for (int i = 1; i <= n*n; i++)
    {
        ans[now_x][now_y]=i;
        int next_x=now_x-1,next_y=now_y+1;
        next_x+=next_x<0?n:0;
        next_y%=n;
        if(ans[next_x][next_y]){
            now_x++;
            continue;
        }
        now_x=next_x;
        now_y=next_y;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}