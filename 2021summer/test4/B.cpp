#include<cstdio>
const long long mode = 1000000007;
long long in[200], n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &in[i]);
    }
    for (int i = 0; i < m; i++)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        in[a] *= b;
        in[a] %= mode;
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= in[a];
            ans %= mode;
        }
        printf("%lld\n", ans);
    }
    return 0;
}