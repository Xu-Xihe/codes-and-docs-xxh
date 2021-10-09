#include<cstdio>
#include<algorithm>
#define maxe 10000000
using namespace std;
int len,W,wi[maxe],vi[maxe],sum[maxe];//len记录物品种类数量，W记录背包容量，wi为物品重量，vi为物品价值，sum为物品个数。
int dp[maxe];
int main(){
    scanf("%d%d",&len,&W);
    for (int i = 1; i <= len; i++)
    {
        scanf("%d%d%d",&vi[i],&wi[i],&sum[i]);
    }
    for (int i = 1; i <= len; i++)
    {
        int max_num=min(sum[i],W/wi[i]);//第i种物品最多能选几件。
        for (int n = 1; max_num > 0; n*=2)
        {
            if(n > max_num)n=max_num;//如果大于num，遍历剩余的。
            max_num-=n;//减去已经遍历过的
            for (int j = W; j >= wi[i]*n; j--)
            {
                dp[j]=max(dp[j],dp[j-wi[i]*n]+vi[i]*n);//正常进行dp
            }
        }
    }
    printf("%d\n",dp[W]);
    return 0;
}