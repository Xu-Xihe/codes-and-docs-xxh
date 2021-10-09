#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[100005],in[100005];
int ci,len;
int big(int in[],int len,int find){
    for(int i = 0; i < len; i++)
    {
        if (in[i]>find) {
            return i;
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&ci);
    for(int zzz = 0; zzz < ci; zzz++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&len);
        for(int i = 0; i < len; i++)
        {
            scanf("%d",&in[i]);
        }
        dp[0]=in[0];
        int lon=1;
        for(int i = 1;i < len; i++)
        {
            for(int j = 0; j < lon; j++)
            {
                printf("%d ",dp[j]);
            }
            printf("\n");
            if (dp[lon-1]<in[i]){
                dp[lon]=in[i];
                lon++;
            }
            else *(lower_bound(dp,dp+lon,in[i]))=in[i];
            printf("%d\n",lon);
            for(int j = 0; j < lon; j++)
            {
                printf("%d ",dp[j]);
            }
            printf("\n\n");
        }
    }
    
}