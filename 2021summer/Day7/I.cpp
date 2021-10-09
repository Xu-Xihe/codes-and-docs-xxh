#include <cstdio>
#define Mid ((l + r) / 2)
#define Len (r - l + 1)
#define Lpos pos * 2
#define Rpos Lpos + 1
#define Lson Lpos, l, Mid
#define Rson Rpos, Mid + 1, r
#define This pos, l, r
const int maxe = 2e5 + 8;
int len, q, in[maxe], tree[maxe * 4], tag[maxe * 4];
inline void upd(int pos)
{
    tree[pos] = tree[Lpos] + tree[Rpos];
}
inline void build(int pos, int l, int r)
{
    if (l == r)
        tree[pos] = in[l];
    else
    {
        build(Lson);
        build(Rson);
        upd(pos);
    }
}
inline void gtg(int pos, int l, int r, int val)
{
    tag[pos] += val;
    tree[pos] += Len * val;
}
inline void stg(int pos, int l, int r)
{
    gtg(Lson, tag[pos]);
    gtg(Rson, tag[pos]);
    tag[pos] = 0;
}
inline void cblk(int pos, int l, int r, int L, int R, int val)
{
    if (L <= l && R >= r)
    {
        gtg(This, val);
        return;
    }
    stg(This);
    if (L <= Mid)
        cblk(Lson, L, R, val);
    if (R > Mid)
        cblk(Rson, L, R, val);
    upd(pos);
}
inline int fblk(int pos, int l, int r, int L, int R)
{
    if (L <= l && R >= r)
    {
        return tree[pos];
    }
    stg(This);
    if (R <= Mid)
        return fblk(Lson, L, R);
    if (L > Mid)
        return fblk(Rson, L, R);
    return fblk(Lson, L, R) + fblk(Rson, L, R);
}
int main()
{
    scanf("%d%d", &len, &q);
    for (int i = 1; i <= len; i++)
    {
        scanf("%d", &in[i]);
    }
    build(1, 1, len);
    while (q--)
    {
        char aa[32];
        int a, b, c;
        scanf("%s%d%d", aa, &a, &b);
        if (aa[0] == 'Q')
        {
            printf("%d\n", fblk(1, 1, len, a, b));
        }
        else
        {
            scanf("%d", &c);
            cblk(1, 1, len, a, b, c);
        }
    }
    return 0;
}