#include <cstdio>
#include <algorithm>
const int maxe = 3e5 + 9;
int n, vaal[2][maxe], sons[2][maxe][2], rank[2][maxe], tott[2], siz[2][maxe], root, inss, type;
char in[10];
#define Lpos son[pos][0]
#define Rpos son[pos][1]
inline int nnew(int v, int *val, int &tot, int *rnk, int *size)
{
    val[++tot] = v;
    size[tot] = 1;
    rnk[tot] = rand();
    return tot;
}
inline void upd(int pos, int *size, int son[maxe][2])
{
    size[pos] = size[Lpos] + size[Rpos] + 1;
}
inline void spv(int pos, int key, int &l, int &r, int *val, int son[maxe][2], int *size)
{
    if (pos == 0)
    {
        l = r = 0;
        return;
    }
    if (val[pos] >= key)
    {
        l = pos;
        spv(Rpos, key, Rpos, r, val, son, size);
    }
    else
    {
        r = pos;
        spv(Lpos, key, l, Lpos, val, son, size);
    }
    upd(pos, size, son);
}
inline void spk(int pos, int key, int &l, int &r, int *size, int son[maxe][2])
{
    if (pos == 0)
    {
        l = r = 0;
        return;
    }
    if (size[Lpos] + 1 <= key)
    {
        l = pos;
        spk(Rpos, key - size[Lpos] - 1, Rpos, r, size, son);
    }
    else
    {
        r = pos;
        spk(Lpos, key, l, Lpos, size, son);
    }
    upd(pos, size, son);
}
inline int tog(int l, int r, int *size, int son[maxe][2], int *rnd)
{
    if (l == 0 || r == 0)
    {
        return l + r;
    }
    if (rnd[l] < rnd[r])
    {
        son[l][1] = tog(son[l][1], r, size, son, rnd);
        upd(l, size, son);
        return l;
    }
    son[r][0] = tog(l, son[r][0], size, son, rnd);
    upd(r, size, son);
    return r;
}
inline void ins(int val, int now)
{
    int l = 0, r = 0;
    spv(root, val, l, r, vaal[now], sons[now], siz[now]);
    root = tog(tog(l, nnew(val, vaal[now], tott[now], rank[now], siz[now]), siz[now], sons[now], rank[now]), r, siz[now], sons[now], rank[now]);
}
inline void del(int val, int now)
{
    int l = 0, r = 0, R = 0;
    spv(root, val, l, r, vaal[now], sons[now], siz[now]);
    spk(l, siz[now][l] - 1, l, R, siz[now], sons[now]);
    root = tog(l, r, siz[now], sons[now], rank[now]);
}
inline int ordv(int val, int now)
{
    int l = 0, r = 0;
    spv(root, val + 1, l, r, vaal[now], sons[now], siz[now]);
    int ans = siz[now][l] + 1;
    root = tog(l, r, siz[now], sons[now], rank[now]);
    return ans;
}
inline int ordk(int val, int now)
{
    int l = 0, r = 0, L = 0;
    spk(root, val, l, r, siz[now], sons[now]);
    printf("afjdkjsl");
    spk(r, 1, L, r, siz[now], sons[now]);
    root = tog(tog(l, L, siz[now], sons[now], rank[now]), r, siz[now], sons[now], rank[now]);
    return vaal[now][L];
}
inline int fan(int put)
{
    int ans = 0, ji = 1e9;
    for (int i = 0; i < 9; i++)
    {
        ans += put / ji;
        put %= ji;
        ji /= 10;
        ans *= 10;
    }
    return ans;
}
int main()
{
    scanf("%d%s", &n, in);
    while (n--)
    {
        scanf("%s%d", in, &inss);
        if (in[0] == 'I')
        {
            ins(inss, type);
            ins(fan(inss), type + 1 % 2);
        }
        if (in[0] == 'D')
        {
            del(inss, type);
            del(fan(inss), type + 1 % 2);
        }
        if (in[0] == 'R')
        {
            printf("%d\n", ordv(inss, type));
        }
        if (in[0] == 'K')
        {
            printf("%d\n", ordk(inss, type));
        }
        if (in[0] == 'E')
        {
            type += 1;
            type %= 2;
        }
    }
    return 0;
}