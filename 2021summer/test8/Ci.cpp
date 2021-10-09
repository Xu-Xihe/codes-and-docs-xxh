#include <cstdio>
#include <queue>
#include <vector>
const int maxe = 2e5 + 9;
int tot, n, m, in[maxe];
struct Nd
{
    int tag, next[2];
};
std::vector<Nd>tree;
std::vector<int> edge[maxe];
inline void ins(int a, int ddd)
{
    int now = 0, u;
    for (int i = 20; i >= 0; i--)
    {
        while(now>=tree.size())
        {
            Nd newd;
            newd.next[0] = newd.next[1] = newd.tag = 0;
            tree.push_back(newd);
        }
        u = (a >> i) & 1;
        if (!tree[now].next[u])
        {
            tree[now].next[u] = ++tot;
        }
        now = tree[now].next[u];
    }
    tree[now].tag = ddd;
}
inline void find(int now, int deep, int wh, int ddd)
{
    //printf("%d --->  %d  :  %d  :  %d \n", wh, now, deep, (wh >> deep) & 1);
    if (deep < 0)
    {
        if (tree[now].tag != ddd)
            edge[tree[now].tag].push_back(ddd);
        return;
    }
    if ((wh >> deep) & 1)
    {
        if (tree[now].next[1])
            find(tree[now].next[1], deep - 1, wh, ddd);
    }
    else
    {
        if (tree[now].next[1])
            find(tree[now].next[1], deep - 1, wh, ddd);
        if (tree[now].next[0])
            find(tree[now].next[0], deep - 1, wh, ddd);
    }
}
struct Rn
{
    int id, deep;
};
int dis[maxe];
bool ji[maxe];
std::queue<Rn> run;
void show(int ttt)
{
    printf("\nshow:");
    if (ttt == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            int len = edge[i].size();
            printf("\n%d :  ", i);
            for (int j = 0; j < len; j++)
            {
                printf("%d ", edge[i][j]);
            }
        }
    }
    if (ttt == 2)
    {
        for (int i = 0; i <= tot; i++)
        {
            printf("%d  :   %d  %d   ---> %d\n", i, tree[i].next[0], tree[i].next[1], tree[i].tag);
        }
    }
    printf("\n");
}
int main()
{
    //freopen("walk.in", "r", stdin);
    //freopen("walk.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
        ins(in[i], i);
    }
    //show(2);
    for (int i = 1; i <= n; i++)
    {
        find(0, 20, in[i], i);
        dis[i] = -1;
    }
    show(1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
    }
    //show(1);
    run.push(Rn{1, 0});
    while (!run.empty())
    {
        Rn top = run.front();
        run.pop();
        ji[top.id] = 1;
        dis[top.id] = top.deep;
        int len = edge[top.id].size();
        for (int i = 0; i < len; i++)
        {
            if (!ji[edge[top.id][i]])
                run.push(Rn{edge[top.id][i], top.deep + 1});
        }
        while (!run.empty() && ji[run.front().id])
            run.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", dis[i]);
    }
    return 0;
}