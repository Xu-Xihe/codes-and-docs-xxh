#include <cstdio>
#include <algorithm>
const int maxe = 1e5 + 9;
int n, m, big[4 * maxe], in[maxe];
long long sum[4 * maxe];
#define Mid ((l + r) >> 1)
#define Len (r - l + 1)
#define Root 1, 1, n
#define Lpos pos << 1
#define Rpos Lpos | 1
#define Lson Lpos, l, Mid
#define Rson Rpos, Mid + 1, r
inline void upd(int pos)
{
    sum[pos] = sum[Lpos] + sum[Rpos];
    big[pos] = std::max(big[Lpos], big[Rpos]);
}
inline void build(int pos, int l, int r)
{
    if (l == r)
    {
        big[pos] = sum[pos] = in[l];
        return;
    }
    build(Lson);
    build(Rson);
    upd(pos);
}
inline void change(int pos, int l, int r, int pot, int val)
{
    if (l == r)
    {
        sum[pos] = val;
        big[pos] = val;
        return;
    }
    if (pot <= Mid)
        change(Lson, pot, val);
    else
        change(Rson, pot, val);
    upd(pos);
}
inline long long check(int pos, int l, int r, int L, int R)
{
    if (L <= l && R >= r)
        return sum[pos];
    if (R <= Mid)
        return check(Lson, L, R);
    if (L > Mid)
        return check(Rson, L, R);
    return check(Lson, L, R) + check(Rson, L, R);
}
inline void mod(int pos, int l, int r, int L, int R, int val)
{
    if (big[pos] < val)
        return;
    if (l == r)
    {
        sum[pos] %= val;
        big[pos] = sum[pos];
        return;
    }
    if (R <= Mid)
        mod(Lson, L, R, val);
    else if (L > Mid)
        mod(Rson, L, R, val);
    else
    {
        mod(Lson, L, R, val);
        mod(Rson, L, R, val);
    }
    upd(pos);
}
int main()
{
    freopen("mod.in", "r", stdin);
    freopen("mod.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
    }
    build(Root);
    int type, a, b, c;
    while (m--)
    {
        scanf("%d%d%d", &type, &a, &b);
        if (type == 1)
            printf("%lld\n", check(Root, a, b));
        if (type == 2)
        {
            scanf("%d", &c);
            mod(Root, a, b, c);
        }
        if (type == 3)
            change(Root, a, b);
    }
    return 0;
}