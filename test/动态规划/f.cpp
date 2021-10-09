#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxe 100009
using namespace std;
int dp[maxe],len,v[maxe],w[maxe],end_a;
int main(){
    while (~scanf("%d",&len))
    {
        memset(dp,0,sizeof(dp));
        for (int i = 1; i <= len; i++)
        {
            scanf("%d%d",&v[i],&w[i]);
        }
        scanf("%d",&end_a);
        for (int i = 1; i <= len; i++)
        {
            for (int j = w[i]; j <= end_a; j++)
            {
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        printf("%d\n",dp[end_a]);
    }
    return 0;
}