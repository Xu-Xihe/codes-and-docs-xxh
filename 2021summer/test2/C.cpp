#include <cstdio>
#include <algorithm>
using std::max;
const int maxe = 3000;
int val[maxe][maxe], n, m, k, dp[maxe][maxe];
bool boon[maxe][maxe];
void show()
{
    printf("\n\n");
    for (int i = k; i >= 0; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d  ", dp[j][i]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            char a[9];
            scanf("%d %s", &val[i][j], a);
            if (a[0] == 'Y')
                boon[i][j] = 1;
        }
    }
    dp[1][k - 1] = val[1][1];
    for (int i = 2; i <= k; i++)
    {
        dp[1][k - i] = dp[1][k - i + 1] + val[i][1];
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int ans = 0, now = 0;
            for (int z = j; z <= k && z <= j + n; z++)
            {
                ans += val[now][i];
                now++;
                for (; boon[now][i]; now++)
                    ans += val[now][i];
                dp[i][j] = max(dp[i][j], dp[i - 1][z] + ans);
                //printf("dp:  %d  %d  %d  : %d  %d  %d\n", i, j, z, ans, dp[i - 1][z], dp[i][j]);
            }
        }
    }
    printf("%d", dp[m][0]);
    //show();
    return 0;
}