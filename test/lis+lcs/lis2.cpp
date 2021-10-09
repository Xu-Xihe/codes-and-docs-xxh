#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxe 100000
using namespace std;
int len,in[maxe],ans;
int dp[maxe];
int main(){
    while (1)
    {
        scanf("%d",&len);
        if(len==0)return 0;
        memset(dp,0,sizeof(dp));
        memset(in,0,sizeof(in));
        for (int i = 1; i <= len; i++)
        {
            scanf("%d",&in[i]);
            dp[i]=in[i];
        }
        ans=in[1];
        for (int i = 1; i <= len; i++)
        {
            for (int j = i-1; j >= 1; j--)
            {
                if (in[i]>in[j])
                {
                    dp[i]=max(dp[i],dp[j]+in[i]);
                }
            }
            if(dp[i]>ans)ans=dp[i];
        }
        /*for (int i = 0; i < len; i++)
        {
            printf("%d ",dp[i+1]);
        }
        printf("\n");*/
        printf("%d\n",ans);
    }
}