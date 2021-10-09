#include <cstdio>
const int maxe = 1e5 + 9;
int len, m;
long long tree[maxe * 6], tag[maxe * 4], in[maxe];
#define Mid ((l + r) / 2)
#define Len (r - l + 1)
#define Lpos pos << 1
#define Rpos Lpos | 1
#define Lson Lpos, l, Mid
#define Rson Rpos, Mid + 1, r
#define This pos, l, r
#define root 1, 1, len
inline void upd(int pos)
{
    tree[pos] = tree[Lpos] + tree[Rpos];
}
inline void gtg(int pos, int l, int r, long long val)
{
    //printf("\nce:  -->  %d\n", pos);
    tag[pos] += val;
    tree[pos] += Len * val;
}
inline void stg(int pos, int l, int r)
{
    //printf("\ngtg-->  %d\n", pos);
    gtg(Lson, tag[pos]);
    gtg(Rson, tag[pos]);
    tag[pos] = 0;
}
inline void build(int pos, int l, int r)
{
    if (l == r)
    {
        tree[pos] = in[l];
        return;
    }
    else
    {
        build(Lson);
        build(Rson);
        upd(pos);
    }
}
inline void cblk(int pos, int l, int r, int L, int R, long long val)
{
    if (L <= l && R >= r)
    {
        //printf("\ncblk-->  %d\n", pos);
        gtg(This, val);
        return;
    }
    //printf("cblk\n");
    stg(This);
    if (L <= Mid)
        cblk(Lson, L, R, val);
    if (R > Mid)
        cblk(Rson, L, R, val);
    upd(pos);
}
long long fblk(int pos, int l, int r, int L, int R)
{
    if (L <= l && R >= r)
        return tree[pos];
    //printf("fblk\n");
    stg(This);
    if (L > Mid)
        return fblk(Rson, L, R);
    if (R <= Mid)
        return fblk(Lson, L, R);
    return fblk(Lson, L, R) + fblk(Rson, L, R);
}
int main()
{
    scanf("%d%d", &len, &m);
    for (int i = 1; i <= len; i++)
    {
        scanf("%d", &in[i]);
    }
    build(root);
    while (m--)
    {
        int aa, a, b, c;
        scanf("%d%d%d", &aa, &a, &b);
        if (aa == 1)
        {
            scanf("%d", &c);
            cblk(root, a, b, c);
        }
        else
            printf("%lld\n", fblk(root, a, b));
    }
    return 0;
}