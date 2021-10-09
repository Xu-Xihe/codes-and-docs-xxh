#include <stdio.h>
#include <string.h>
#define ll unsigned long long
const int MAXN = 5000010;
int dp[MAXN], n, m;
ll val[100009];
int main()
{
    dp[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (dp[i])
            continue;
        for (int j = i; j < MAXN; j += i)
        {
            if (!dp[j])
                dp[j] = j;
            dp[j] = dp[j] / i * (i - 1);
        }
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
    }
    while (m--)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 0)
        {
            ll x;
            scanf("%d", &x);
            for (int i = l; i <= r; i++)
            {
                val[i] *= x;
            }
        }
        else
        {
            ll ans = 0;
            for (int i = l; i <= r; i++)
            {
                ans += dp[val[i]];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}