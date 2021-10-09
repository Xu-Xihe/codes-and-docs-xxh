#include <cstdio>
const int maxe = 2009;
int yang[maxe][maxe], ans[maxe][maxe], t, k, max = 1;
inline void hui(int from, int len)
{
    for (int i = from; i <= len; i++)
    {
        yang[i][1] = 1;
        ans[i][1] = ans[i - 1][1];
        for (int j = 2; j <= i + 1; j++)
        {
            yang[i][j] = yang[i - 1][j - 1] + yang[i - 1][j];
            yang[i][j] %= k;
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if (j == i + 1)
                ans[i][j] += ans[i - 1][j - 1];
            if (yang[i][j] == 0)
                ans[i][j]++;
        }
    }
}
int main()
{
    scanf("%d%d", &t, &k);
    yang[0][1] = 1;
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (m > n )
            m = n ;
        if (n > max)
        {
            hui(max, n);
            max = n;
        }
        printf("%d\n", ans[n][m+1]);
    }
    return 0;
}