#include<cstdio>
using namespace std;
int len,ji[]={0,1,5,10,25,50};
int dp[8][10000];
int main()
{
    while(~scanf("%d",&len))
    {
        for(int i=1;i<=5;i++)dp[i][0]=1;
        for(int zl = 1; zl <= 5; zl++)
        {
            for(int i = 1; i <= len; i++)
            {
                dp[zl][i]=dp[zl-1][i];
                if(i>=ji[zl])dp[zl][i]+=dp[zl][i-ji[zl]];
            }
        }
        printf("%d\n",dp[5][len]);
    }
    return 0;
}