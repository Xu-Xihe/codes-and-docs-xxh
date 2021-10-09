#include <cstdio>
#define ll unsigned long long
const int maxe = 1e5 + 9;
inline ll V(ll last, ll now, ll P)
{
    return (now * now * now - last * last * last) * P;
}
int n, m;
ll mi[maxe], R[maxe], tree[maxe];
inline void add(int x, ll val)
{
    for (; x <= n; x += x & -x)
        tree[x] += val;
}
inline ll find(int x)
{
    ll ans = 0;
    for (; x > 0; x -= x & -x)
        ans += tree[x];
    return ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &mi[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &R[i]);
        add(i, V(0, R[i], mi[i]));
    }
    while (m--)
    {
        int l, r, x, op;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            scanf("%d", &x);
            for (int i = l; i <= r; i++)
            {
                add(i, V(R[i], R[i] + x, mi[i]));
                R[i] += x;
            }
        }
        else
        {
            printf("%lld\n", find(r) - find(l - 1));
        }
    }
    return 0;
}