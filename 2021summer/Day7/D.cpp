#include <cstdio>
const int maxe = 1e6 + 10;
long long treeb[maxe], treei[maxe];
int len, q, last;
long long find(int x, long long *p)
{
    long long ans = 0;
    for (; x > 0; x -= x & -x)
        ans += p[x];
    return ans;
}
void add(int x, long long val, long long *p)
{
    for (; x <= len; x += x & -x)
        p[x] += val;
}
long long sum(int r)
{
    if (r == 0)
        return 0;
    return (r + (long long)1) * find(r, treeb) - find(r, treei);
}
int main()
{
    scanf("%d%d", &len, &q);
    for (int i = 1; i <= len; i++)
    {
        long long a;
        scanf("%lld", &a);
        add(i, a - last, treeb);
        add(i, (a - last) * i, treei);
        last = a;
    }
    while (q--)
    {
        int wh;
        long long a, b, c;
        scanf("%d%lld%lld", &wh, &a, &b);
        if (wh == 1)
        {
            scanf("%lld", &c);
            add(a, c, treeb);
            add(a, c * a, treei);
            add(b + 1, -c, treeb);
            add(b + 1, -c * (b + 1), treei);
        }
        else
        {
            printf("%lld\n", sum(b) - sum(a - 1));
        }
    }
    return 0;
}