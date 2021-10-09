#include <cstdio>
const int maxe = 1e5 + 5;
int n, m;
long long out = 2e15, shu[maxe][2], out2;
bool dfs(int free, int roof, long long ans)
{
    if (roof == n - 1)
    {
        long long a = ans + shu[roof][0] * (free + 1) * (free + 1) + shu[roof][1] * (free + 1);
        if (a < out)
        {
            out = a;
            return false;
        }
        else
            return true;
    }
    for (int i = 0; i <= free; i++)
    {
        int next = ans + shu[roof][0] * (i + 1) * (i + 1) + shu[roof][1] * (i + 1);
        if (dfs(free - i, roof + 1, next))
        {
            return true;
        };
    }
    return false;
}
int main()
{
    //freopen("function.in","r",stdin);
    //freopen("function.out","w",stdout);
    scanf("%d%d", &n, &m);
    m -= n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        out2 += c;
        shu[i][0] = a;
        shu[i][1] = b;
    }
    dfs(m, 0, 0);
    printf("%lld", out + out2);
    return 0;
}