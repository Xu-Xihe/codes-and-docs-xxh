#include <cstdio>
#define maxe 1000000
int n, m, fa[maxe], ans;
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void together(int x, int y)
{
    int a = find(x), b = find(y);
    fa[a] = b;
}
int main()
{
    while (1)
    {
        ans = 0;
        scanf("%d", &n);
        if (!n)
            return 0;
        scanf("%d", &m);
        for (int i = 0; i < n + 1; i++)
        {
            fa[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            together(a, b);
        }
        for (int i = 1; i <= n; i++)
        {
            ans += fa[i] == i ? 1 : 0;
        }
        printf("%d\n", ans - 1);
    }
}