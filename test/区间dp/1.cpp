#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e2 + 100;
char str[maxn];
int dp[maxn][maxn];
int main()
{
    while(~scanf("%s", str) && strcmp(str, "end"))
    {
        memset(dp, 0, sizeof(dp));
        int n = strlen(str);
        for(int len = 2; len <= n; len++)
        {
            for(int i = 0; i < n; i++)
            {
                if(i + len - 1 > n) break;
                int j = i + len - 1;
                if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else dp[i][j] = dp[i + 1][j - 1];

                for(int k = i; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                printf("%d ",dp[i+1][j+1]);
            }
            printf("\n");
        }
    }
}