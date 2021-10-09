#include <cstdio>
#include <algorithm>
using std::max;
int n, m, num[8], pot[400], dp[45][45][45][45];
inline int out(int a)
{
    return a - 1 > 0 ? a - 1 : 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &pot[i]);
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        num[a]++;
    }
    for (int a = 0; a <= num[1]; a++)
    {
        for (int b = 0; b <= num[2]; b++)
        {
            for (int c = 0; c <= num[3]; c++)
            {
                for (int d = 0; d <= num[4]; d++)
                {
                    dp[a][b][c][d] = max(max(dp[out(a)][b][c][d], dp[a][out(b)][c][d]), max(dp[a][b][out(c)][d], dp[a][b][c][out(d)])) + pot[a + b * 2 + c * 3 + d * 4 + 1];
                }
            }
        }
    }
    printf("%d", dp[num[1]][num[2]][num[3]][num[4]]);
    return 0;
}