#include <cstdio>
#include<algorithm>
#define maxe 1000
using namespace std;
int dp[maxe],w[maxe],v[maxe],len,Wi;//w指重量，v指价值
int main(){
    scanf("%d%d",&len,&Wi);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d",&w[i+1],&v[i+1]);
    }
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= Wi; j++)
        {
            if (j>=w[i])
            {
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n",dp[Wi]);
    return 0;
}