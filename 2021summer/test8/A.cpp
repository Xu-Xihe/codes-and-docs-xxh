#include <cstdio>
#include <algorithm>
#include <set>
#include<vector>
const int maxe = 500;
struct Sp
{
    int t, w, v;
} shop[maxe], ask[100009];
int n, m, maxw;
int dp[maxe][maxe];
inline bool cmp(Sp a, Sp b)
{
    return a.t < b.t;
}
inline void sml()
{
    int ans[100009];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxw; j++)
        {
            if (j < shop[i].w)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - shop[i].w] + shop[i].v);
        }
    }
    for (int i = 1, now = 1; i <= m; i++)
    {
        while (shop[now].t <= ask[i].t && now <= n)
            now++;
        ans[ask[i].v] = dp[now - 1][ask[i].w];
        //printf("%d  %d  %d  %d  %d\n", shop[now].t, ask[i].v, now,ask[i].w,dp[now - 1][ask[i].w]);
    }
    //show();
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
}
struct Rn
{
    int val, wei;
    bool friend operator<(Rn a, Rn b)
    {
        return a.wei == b.wei ? a.val > b.val : a.wei < b.wei;
    }
};
std::multiset<Rn> run;
std::vector<Rn> lin;
void show()
{
    printf("\nrun in:\n");
    for (auto i : run)
    {
        printf("%d %d\n", i.wei, i.val);
    }
    printf("\n");
}
int main()
{
    freopen("market.in", "r", stdin);
    freopen("market.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &shop[i].w, &shop[i].v, &shop[i].t);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &ask[i].t, &ask[i].w);
        ask[i].v = i;
        maxw = std::max(maxw, ask[i].w);
    }
    std::sort(shop + 1, shop + 1 + n, cmp);
    std::sort(ask + 1, ask + 1 + m, cmp);
    if (maxw <= 350)
    {
        sml();
        return 0;
    }
    else
    {
        int ans = 0;
        for (int i = 1, now = 1; i <= m; i++)
        {
            for (; shop[now].t <= ask[i].t&&now<=n; now++)
            {
                for (auto j : run)
                {
                    if (j.wei + shop[now].w <= maxw)
                    {
                        //printf("cwshi   %d  %d  %d   %d  %d\n", j.wei, shop[now].w, j.val, shop[now].v);
                        lin.push_back(Rn{j.val + shop[now].v, j.wei + shop[now].w});
                    }
                }
                int len = lin.size();
                for (int j = 0; j <len; j++)
                {
                    run.insert(lin[j]);
                }
                lin.clear();
                if (shop[now].w <= maxw)
                    run.insert(Rn{shop[now].v, shop[now].w});
            }
            std::multiset<Rn>::iterator end = run.upper_bound(Rn{0, ask[i].w});
            end--;
            while (1)
            {
                Rn top = *end;
                if (top.val >= ans)
                {
                    ans = top.val;
                    std::multiset<Rn>::iterator lin = end;
                    lin++;
                    run.erase(lin, run.upper_bound(Rn{0, ask[i].w}));
                }
                if (end == run.begin())
                    break;
                end--;
            }
            printf("%d\n", ans);
        }
        return 0;
    }
}