#include <cstdio>
#include <algorithm>
const int maxe = 1e6 + 9;
int n, m, ans[maxe], szn[maxe][2], ddd = -1, now = 1;
struct build
{
    int pla, hig, tag;
} buds[maxe], fqy[maxe];
namespace stack
{
    inline int top()
    {
        return ddd == -1 ? -1 : szn[ddd][1];
    }
    inline void push(build in)
    {
        szn[++ddd][0] = in.pla;
        szn[ddd][1] = in.hig;
    }
    inline bool pop()
    {
        if (ddd < 0)
            return false;
        ddd--;
        return true;
    }
    inline int size()
    {
        return ddd;
    }
    inline void clear()
    {
        ddd = -1;
    }
    inline void show()
    {
        printf("\n now len = %d\n", ddd + 1);
        for (int i = 0; i <= ddd; i++)
        {
            printf("%d  ", szn[i][0]);
        }
        printf("\n");
    }
}
inline bool cmp(build a, build b)
{
    return a.pla < b.pla;
}
inline int find(int same, bool sss)
{
    int sta = 0, end = stack::size();
    if (end == -1)
        return 0;
    while (1)
    {
        if (sta + 1 == end || sta == end)
        {
            //printf("sjdfj  %d  %d\n", sta, end);
            if (szn[sta][0] <= same)
                return stack::size() - sta + 1;
            return stack::size() - end + 1;
        }
        int mid = (sta + end) / 2;
        if (!sss)
        {
            if (same <= szn[mid][0])
                end = mid;
            else
                sta = mid;
        }
        else
        {
            if (same >= szn[mid][0])
                end = mid;
            else
                sta = mid;
        }
        //printf("ceshi :  %d  %d\n", sta, end);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &buds[i].pla, &buds[i].hig);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &fqy[i].hig, &fqy[i].pla);
        fqy[i].tag = i;
    }
    std::sort(buds + 1, buds + 1 + n, cmp);
    std::sort(fqy + 1, fqy + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        while (buds[now].pla < fqy[i].pla && now <= n)
        {
            while (stack::top() > -1 && stack::top() <= buds[now].hig)
                stack::pop();
            stack::push(buds[now]);
            now++;
        }
        ans[fqy[i].tag] += find(fqy[i].pla - fqy[i].hig, 0);
    }
    now = n;
    stack::clear();
    for (int i = m; i > 0; i--)
    {
        while (buds[now].pla >= fqy[i].pla && now > 0)
        {
            while (stack::top() > -1 && stack::top() <= buds[now].hig)
                stack::pop();
            stack::push(buds[now]);
            now--;
        }
        //stack::show();
        ans[fqy[i].tag] += find(fqy[i].pla + fqy[i].hig, 1);
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
}