#include <cstdio>
#include <algorithm>
const int maxe = 1e6 + 9;
int n, m, ans[maxe][2], put;
bool ji[maxe][2];
struct build
{
    int hig, pla;
} buds[maxe];
inline void chu(int wei, int sta, int end, int add)
{
    int max = 0;
    for (int i = sta; i != end + add; i += add)
    {
        ans[i][wei] = ans[i - 1][wei];
        //printf("ce:  %d  %d  %d  %d  %d\n", i, buds[i].hig, max, ans[i][wei]);
        if (buds[i].hig > max)
        {
            max = buds[i].hig;
            ji[i][wei] = 1;
            ans[i][wei]++;
        }
    }
}
inline int find(int wei, int sta, int end, int add)
{
    int max = 0;
    if(sta>n||sta<1)
        return 2e9;
    for (int i = sta; i != end + add; i += add)
    {
        if (ji[i][wei])
            return i;
        if (buds[i].hig > max)
        {
            max = buds[i].hig;
            put++;
        }
    }
    return 2e9;
}
inline bool cmp(build a, build b)
{
    return a.pla < b.pla;
}
inline int check(int cap)
{
    int sta = 1, end = n;
    while (1)
    {
        if (sta + 1 == end || sta == end)
        {
            //printf("fdsaf: %d  %d  %d  %d\n", cap, sta,end, buds[sta].pla);
            if (cap < buds[end].pla)
                return sta;
            else
                return end;
        }
        int mid = (end + sta) / 2;
        if (buds[mid].pla > cap)
            end = mid;
        else
            sta = mid;
    }
}
int main()
{
    freopen("DS.in", "r", stdin);
    freopen("DS.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        buds[i].hig = b;
        buds[i].pla = a;
    }
    std::sort(buds + 1, buds + n + 1, cmp);
    chu(0, 1, n, 1);
    chu(1, n, 1, -1);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        put = 0;
        int Rmax = b + a, Lmax = b - a, linshi = b;
        b = check(b);
        if (buds[b].pla < linshi)
            b++;
        Rmax = check(Rmax);
        Lmax = check(Lmax);
        //printf("first : %d  %d  %d\n\n", b, Rmax, Lmax);
        int lin = find(0, b, Rmax, 1);
        //printf("round 1: %d %d --> ", lin, put);
        if (lin < 2e9)
            put += ans[Rmax][0] - ans[lin - 1][0];
        //printf("%d  -  %d  =  %d", ans[Rmax][0], ans[lin][0], put);
        lin = find(1, b - 1, Lmax, -1);
        //printf("    round 2:  %d   %d --> ", lin, put);
        if (lin != 2e9)
            put += ans[lin][1] - ans[Lmax - 1][1];
        printf("%d\n", put);
    }
    return 0;
}