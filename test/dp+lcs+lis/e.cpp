#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxe 90000000
using namespace std;
int dp[maxe],len,m;
int in[maxe];
void pr(int len,int what[]){
    for (int i = 0; i < len; i++)
    {
        printf("%d  ",what[i+1]);
    }
    printf("\n\n\n");
}
int maxee(int dp[],int len){
    int ma=0;
    for (int i = 0; i < len; i++)
    {
        
    }
    return ma;
}
int main(){
    while(~scanf("%d%d",&m,&len)){
        for (int i = 1; i <= len; i++)
        {
            scanf("%d",&in[i]);
        }
        memset(dp,0,sizeof(dp));
        int k=0,kv=0,nk=0;
        for (int j = 1; j <= len; j++)
        {
            dp[j]=max(dp[j-1]+in[j],in[j]);
        }
        pr(len,dp);
        for (int i = 2; i <= m; i++)
        {
            for (int j = len; j > 0; j--)
            {
                printf("%d--%d--%d--%d--%d\n",j,dp[j-1],in[j],dp[maxee(dp,j)],maxee(dp,j));
                dp[j]=max(dp[j-1]+in[j],dp[maxee(dp,j)]+in[j]);
            }
            pr(len,dp);
        }
        printf("%d\n",dp[len]);
    }
    return 0;
}