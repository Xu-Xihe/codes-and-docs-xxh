#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
const int maxe = 3e5;
int n, m, k, at, bt, aw, bw, val[maxe], ans;
std::vector<int> next[maxe];
struct pot
{
    int now, wei, dep;
};
std::queue<pot> run;
int main()
{
    freopen("adventure.in", "r", stdin);
    freopen("adventure.out", "w", stdout);
    scanf("%d%d%d%d%d%d%d", &n, &m, &k, &at, &bt, &aw, &bw);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        val[a] += b;
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        next[a].push_back(b);
    }
    run.push(pot{1, 0, 0});
    while (!run.empty())
    {
        pot top = run.front();
        top.wei += val[top.now];
        //printf("\n%d  %d  %d %d  %d  ", top.now, top.wei, top.dep,(top.dep / at),(top.dep / at) * aw);
        if (top.dep % at == 0)
        {
            ans = std::max(ans, top.wei - (top.dep / at) * aw);
            //printf("at-- ");
        }
        if (top.dep % bt == 0)
        {
            ans = std::max(ans, top.wei - (top.dep / bt) * bw);
            //printf("bt-- ");
        }
        //printf("%d\n", ans);
        for (auto i : next[top.now])
        {
            run.push(pot{i, top.wei, top.dep + 1});
        }
        run.pop();
    }
    printf("%d\n", ans);
    return 0;
}