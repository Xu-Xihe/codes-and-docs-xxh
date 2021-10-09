#include <cstdio>
const int maxe = 5e2 + 10;
int n, m, q, tree[maxe][maxe];
int find(int y, int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i)
    {
        for (int j = y; j > 0; j -= j & -j)
        {
            ans += tree[i][j];
        }
    }
    return ans;
}
void add(int x, int y, int val)
{
    for (int i = x; i <= n; i += i & -i)
    {
        for (int j = y; j <= m; j += j & -j)
        {
            tree[i][j] += val;
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a;
            scanf("%d", &a);
            add(i, j, a);
        }
    }
    while (q--)
    {
        char s[23];
        int a, b, c, d;
        scanf("%s%d%d%d", s, &a, &b, &c);
        if (s[0] == 'Q')
        {
            scanf("%d", &d);
            printf("%d\n", find(c - 1, a - 1) + find(d, b) - find(c - 1, b) - find(d, a - 1));
        }
        else
        {
            add(a, b, c);
        }
    }
    return 0;
}