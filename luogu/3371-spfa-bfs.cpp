#include <cstdio>
#include <queue>
#include <vector>
const int maxe = 1e5 + 9, INF = 2147483647;
int n, m, sta, dis[maxe];
int pass[maxe];
struct node //邻接链表存图
{
    int next, val;
};
std::vector<node> edges[maxe];
std::queue<int> run;
bool in[maxe];
int main()
{
    scanf("%d%d%d", &n, &m, &sta);
    for (int i = 1; i <= n; i++) //初始化
    {
        dis[i] = INF;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        edges[a].push_back(node{b, v});
    }
    run.push(sta); //将起点加入队列
    dis[sta] = 0;
    while (!run.empty())
    {
        int now = run.front();
        run.pop();
        in[now] = 0; //使队列中没有now
        int len = edges[now].size();
        for (int i = 0; i < len; i++)
        {
            if (dis[edges[now][i].next] > dis[now] + edges[now][i].val) //松弛操作
            {
                dis[edges[now][i].next] = dis[now] + edges[now][i].val;
                pass[edges[now][i].next] = pass[now] + 1;
                if (pass[edges[now][i].next] > n)
                {
                    printf("orz");
                    return 0;
                }
                if (!in[edges[now][i].next]) //如果队列中没有
                {
                    run.push(edges[now][i].next); //加入队列并标记
                    in[edges[now][i].next] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dis[i]);
    }
    return 0;
}