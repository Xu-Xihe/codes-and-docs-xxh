#include <algorithm>
#include <cstdio>
using std::sort;
namespace FastIO
{
    inline void fin(int &ans)
    {
        ans = 0;
        char fir = 0, num;
        num = getchar();
        while (num < '0' || num > '9')
        {
            fir = num;
            num = getchar();
        }
        while (num >= '0' && num <= '9')
        {
            ans *= 10;
            ans += num - '0';
            num = getchar();
        }
        if (fir == '-')
            ans *= -1;
    }
}
const int maxe = 5e6 + 6;
int rad[maxe], val[maxe], son[maxe][2], size[maxe], root = 1, tot, in[maxe];
int len, m, last, ans;
#define Ls son[pos][0]
#define Rs son[pos][1]
inline void upd(int pos)
{
    size[pos] = size[Ls] + size[Rs] + 1;
}
inline int bnw(int x)
{
    size[++tot] = 1;
    rad[tot] = rand();
    val[tot] = x;
    return tot;
}
inline void spv(int pos, int key, int &l, int &r)
{
    if (pos == 0)
    {
        l = r = 0;
        return;
    }
    if (val[pos] <= key)
    {
        l = pos;
        spv(Rs, key, Rs, r);
    }
    else
    {
        r = pos;
        spv(Ls, key, l, Ls);
    }
    upd(pos);
}
inline void spk(int pos, int key, int &l, int &r)
{
    if (pos == 0)
    {
        l = r = 0;
        return;
    }
    if (size[Ls] + 1 <= key)
    {
        l = pos;
        spk(Rs, key - size[Ls] - 1, Rs, r);
    }
    else
    {
        r = pos;
        spk(Ls, key, l, Ls);
    }
    upd(pos);
}
inline int tog(int l, int r)
{
    if (l == 0 || r == 0)
        return l + r;
    if (rad[l] < rad[r])
    {
        son[l][1] = tog(son[l][1], r);
        upd(l);
        return l;
    }
    son[r][0] = tog(l, son[r][0]);
    upd(r);
    return r;
}
#define mid ((l + r) >> 1)
inline int build(int l, int r)
{
    if (l > r)
        return 0;
    int pos = bnw(in[mid]);
    Ls = build(l, mid - 1);
    Rs = build(mid + 1, r);
    upd(pos);
    return pos;
}
inline void ins(int v)
{
    int ll = 0, rr = 0;
    spv(root, v, ll, rr);
    root = tog(tog(ll, bnw(v)), rr);
}
inline void del(int v)
{
    int ll = 0, rr = 0, LL = 0;
    spv(root, v, ll, rr);
    spv(ll, v - 1, ll, LL);
    LL = tog(son[LL][0], son[LL][1]);
    root = tog(tog(ll, LL), rr);
}
inline int fir(int v)
{
    int ll = 0, rr = 0, RR = 0;
    spv(root, v - 1, ll, rr);
    spk(ll, size[ll] - 1, ll, RR);
    root = tog(tog(ll, RR), rr);
    return val[RR];
}
inline int bak(int v)
{
    int ll = 0, rr = 0, LL = 0;
    spv(root, v, ll, rr);
    spk(rr, 1, LL, rr);
    root = tog(tog(ll, LL), rr);
    return val[LL];
}
inline int odv(int v)
{
    int ll = 0, rr = 0;
    spv(root, v - 1, ll, rr);
    int r = size[ll];
    root = tog(ll, rr);
    return r + 1;
}
inline int odk(int v)
{
    int ll = 0, rr = 0, RR = 0;
    spk(root, v, ll, rr);
    spk(ll, v - 1, ll, RR);
    root = tog(tog(ll, RR), rr);
    return val[RR];
}
int main()
{
    FastIO::fin(len);
    FastIO::fin(m);
    for (int i = 1; i <= len; i++)
    {
        FastIO::fin(in[i]);
    }
    sort(in + 1, in + len + 1);
    build(1, len);
    while (m--)
    {
        int opt, x;
        FastIO::fin(opt);
        FastIO::fin(x);
        x ^= last;
        if (opt == 1)
            ins(x);
        if (opt == 2)
            del(x);
        if (opt == 3)
        {
            last = odv(x);
            ans ^= last;
        }
        if (opt == 4)
        {
            last = odk(x);
            ans ^= last;
        }
        if (opt == 5)
        {
            last = fir(x);
            ans ^= last;
        }
        if (opt == 6)
        {
            last = bak(x);
            ans ^= last;
        }
    }
    printf("%d", ans);
    return 0;
}