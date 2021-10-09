#include <cstdio>
const int maxe = 2e6;
int n, q, tree[maxe];
int find(int x)
{
    int ans = 0;
    for (; x > 0; x -= (x & -x))
    {
        ans += tree[x];
        //printf("func:-->%d   %d  \n\n", x, tree[x]);
    }
    return ans;
}
void add(int x, int val)
{
    for (; x <= n; x += x & -x)
        tree[x] += val;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        add(i, a);
    }
    while (q--)
    {
        char a[212];
        int x, y;
        scanf("%s%d%d", a, &x, &y);
        //printf("ce-->%d  %c %d %d\n",q,a[0],x,y);
        if (a[0] == 'Q')
        {
            printf("%d\n", find(y) - find(x - 1));
        }
        else
            add(x, y);
    }
    return 0;
}