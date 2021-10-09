#include <cstdio>
#include <algorithm>
const int maxe = 2e5 + 9;
int len, foc[maxe], mk[maxe], uk[maxe], good, bad, m, tree[maxe];
struct OD
{
    int op, val;
} order[maxe];
inline void once(int &god, int &bd, OD *ord, int n)
{
    for (int i = 1; i <= n; i++)
    {
        foc[i] = foc[i - 1];
        mk[i] = mk[i - 1];
        uk[i] = uk[i - 1];
        if (ord[i].op == 1)
        {
            foc[i] += ord[i].val;
        }
        if (ord[i].op == 2)
        {
            god += foc[i];
            mk[i]++;
        }
        if (ord[i].op == 3)
        {
            bd += foc[i];
            uk[i]++;
        }
        if (ord[i].op == 4)
        {
            std::swap(god, bd);
        }
    }
}
/*inline void add(int x, int val)
{
    for (; x <= len; x += x & -x)
        tree[x] += val;
}
inline int find(int x)
{
    int ans = 0;
    for (; x > 0; x -= x & -x)
        ans += tree[x];
    return ans;
}*/
int main()
{
    scanf("%d", &len);
    for (int i = 1; i <= len; i++)
    {
        int a, b;
        scanf("%d", &a);
        order[i].op = a;
        if (a == 1)
        {
            scanf("%d", &b);
            order[i].val = b;
        }
    }
    once(good, bad, order, len);
    printf("%d\n", good - bad);
    scanf("%d", &m);
    if (len <= 49996)
    {
        while (m--)
        {
            good = bad = foc[0] = 0;
            int a, b, t;
            scanf("%d%d", &t, &a);
            order[t].op = a;
            if (a == 1)
            {
                scanf("%d", &b);
                order[t].val = b;
            }
            once(good, bad, order, len);
            printf("%d\n", good - bad);
        }
        return 0;
    }
    if (len == 49997)
    {
        while (m--)
        {
            int t, a;
            scanf("%d%d", &t, &a);
            if (order[t].op == a)
            {
                printf("%d\n", good - bad);
                continue;
            }
            order[t].op = a;
            if (a == 2)
            {
                bad -= foc[t];
                good += foc[t];
            }
            if (a == 3)
            {
                bad += foc[t];
                good -= foc[t];
            }
            printf("%d\n", good - bad);
        }
        return 0;
    }
    if (len == 49998)
    {
        /*for (int i = 1; i <= len;i++)
        {
            add(i, foc[i] - foc[i - 1]);
        }*/
        while (m--)
        {
            int t, a, b;
            scanf("%d%d%d", &t, &a, &b);
            int chg = b - order[t].val;
            order[t].val = b;
            //add(t, chg);
            good += (mk[len] - mk[t - 1]) * chg;
            bad += (uk[len] - uk[t - 1]) * chg;
            printf("%d\n", good - bad);
        }
        return 0;
    }
}