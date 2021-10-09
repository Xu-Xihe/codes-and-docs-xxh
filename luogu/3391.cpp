#include<cstdio>
#include<algorithm>
const int maxe = 1e5 + 9;
int root, tot,n,m;
int val[maxe], son[maxe][2], rnd[maxe],size[maxe];
bool tag[maxe];
inline int nnd(int x)
{
    rnd[++tot] = rand();
    size[tot] = 1;
    val[tot] = x;
    return tot;
}
#define Ls son[pos][0]
#define Rs son[pos][1]
#define Mid ((l+r)/2)
inline void upd(int pos)
{
    size[pos] = size[Ls] + size[Rs];
}
inline int build(int l,int r)
{
    if(l>r)
        return 0;
    int pos = Mid;
    nnd(pos);
    Ls = build(l, pos - 1);
    Rs = build(pos + 1, r);
    upd(pos);
}
int main()
{
    scanf("%d%d", &n, &m);
    build(1, n);
    while (m--)
    {
        int l, r; 

    }
    return 0;
}