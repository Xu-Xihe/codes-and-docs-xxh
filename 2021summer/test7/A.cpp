#include <cstdio>
#include <set>
#include <queue>
#include <vector>
const int maxe = 2e5 + 9;
int n, ans, gai[maxe];
std::vector<int> szn[maxe];
struct node
{
    int id, l, r;
    bool friend operator<(node a, node b)
    {
        return a.r < b.r;
    }
};
std::multiset<node> in;
struct R
{
    int id, val;
    bool friend operator<(R a, R b)
    {
        return a.val < b.val;
    }
};
std::priority_queue<R> run;
inline int find(node now)
{
    std::multiset<node>::iterator sta = in.upper_bound(node{0, 0, now.l});
    int ans = 0;
    for (; sta != in.end(); sta++)
    {
        node is = *sta;
        /*for(auto i:in)
        {
            printf("%d %d %d\n", i.id, i.l, i.r);
        }*/
        if (is.l < now.r)
        {
            gai[is.id]++;
            ans++;
            szn[is.id].push_back(now.id);
            szn[now.id].push_back(is.id);
        }
    }
    return ans;
}
void show(int *out, int len = n)
{
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", out[i + 1]);
    }
    printf("\n");
}
int main()
{
    freopen("clique.in", "r", stdin);
    freopen("clique.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, b;
        scanf("%d%d", &x, &b);
        gai[i] = find(node{i, x - b, x + b});
        in.insert(node{i, x - b, x + b}); //show(gai);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!gai[i])
            run.push(R{i, gai[i]});
    }
    while (!run.empty())
    {
        ans++;
        R top = run.top();
        run.pop();
        int len = szn[top.id].size();
        gai[top.id] = 0;
        for (int i = 0; i < len; i++)
        {
            gai[szn[top.id][i]]--;
            if (gai[szn[top.id][i]] > 0)
                run.push(R{szn[top.id][i], gai[szn[top.id][i]]});
        }
        szn[top.id].clear();
        while (!run.empty() && gai[run.top().id] != run.top().val)
            run.pop();
    }
    printf("%d", n - ans);
    return 0;
}