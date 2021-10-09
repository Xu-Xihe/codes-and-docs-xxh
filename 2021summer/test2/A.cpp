#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
const int maxe = 100;
const long long big = 9223372036854775807;
long long dp[maxe][maxe][2], ans;
int t, n;
void show(int len, int sign)
{
    printf("\n\n");
    for (int i = 1; i <= len * 2; i++)
    {
        printf("%d:  ", i);
        for (int j = 1; j <= len * 2; j++)
        {
            printf("%lld  ", dp[i][j][sign]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int main()
{
    //freopen("pao.in", "r", stdin);
    //freopen("pao.out", "w", stdout);
    scanf("%d", &t);
    ans = big;
    while (t--)
    {
        ans = -big;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &dp[i][i][0]);
            dp[i + n][i + n][0] = dp[i][i][1] = dp[i + n][i + n][1] = dp[i][i][0];
        }
        for (int len = 2; len <= n; len++)
        {
            for (int sta = 1; sta <= n * 2 - len + 1; sta++)
            {
                int end = sta + len - 1;
                dp[sta][end][0] = -big;
                dp[sta][end][1] = big;
                for (int z = sta; z < end; z++)
                {
                    dp[sta][end][0] = max(dp[sta][end][0], dp[sta][z][0] + dp[z + 1][end][0]);
                    dp[sta][end][1] = min(dp[sta][end][1], dp[sta][z][1] + dp[z + 1][end][1]);
                }
                for (int z = sta; z < end; z++)
                {
                    for (int y = z + 1; y < end; y++)
                    {
                        dp[sta][end][0] = max(dp[sta][end][0], max(dp[sta][z][0] * dp[y + 1][end][0],dp[sta][z][1] * dp[y + 1][end][1]) - dp[z + 1][y][1]);
                        dp[sta][end][1] = min(dp[sta][end][1], min(dp[sta][z][1]*dp[y+1][end][1],min(dp[sta][z][1] * dp[y + 1][end][0], dp[sta][z][0] * dp[y + 1][end][1])) - dp[z + 1][y][0]);
                    }
                }
                if (len == n)
                    ans = max(ans,dp[sta][end][0]);
            }
        }
        printf("%lld\n", n == 1 ? dp[1][1][0] : ans);
        //show(n, 0);
        //show(n, 1);
    }
    return 0;
}