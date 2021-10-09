#include<cstdio>
#include<algorithm>
#define maxe 2100
using namespace std;
int dp[maxe][maxe],len,start;
void pr(int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%d ",dp[i+1][j+1]);
        }
        printf("\n");
    }
    
}
void newdp(){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            dp[i+1][j+1]=1e9;
        }
    }
}
int main(){
    while (~scanf("%d%d",&start,&len))
    {
        newdp();
        for (int i = 1; i <= len; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            scanf("%d",&dp[a][b]);
        }
        for (int zzz = 1; zzz <= len; zzz++)
        {
            for (int i = 1; i <= len; i++)
            {
                for (int j = 1; j <= len; j++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][zzz]+dp[zzz][j]);
                }
                //pr(len);
                //printf("\n\n\n");
            }
        }
        printf("%d\n",dp[1][start]);
    }
    return 0;
}