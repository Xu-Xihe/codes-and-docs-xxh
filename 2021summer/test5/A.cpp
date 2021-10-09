#include <cstdio>
int len, in;
int ans;
int main()
{
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);
    scanf("%d%d", &len, &ans);
    for (int i = 1; i < len; i++)
    {
        scanf("%d", &in);
        ans ^= in;
    }
    printf("%d", ans);
    return 0;
}