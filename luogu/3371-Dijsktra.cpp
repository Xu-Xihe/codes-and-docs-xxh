#include <cstdio>
#include <vector>
#include <queue>
const int maxe = 1e5 + 9, INF = 2147483647;
struct node //邻接链表存图
{
    int next, val;
    bool friend operator<(node a, node b)
    {
        return a.val > b.val;
    }
};
std::vector<node> edges[maxe];
std::priority_queue<node> run;
int n, m, sta, dis[maxe];
bool ji[maxe];
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
    dis[sta] = 0;  //自己倒自己为0
    int now = sta; //当前要被加入点集的节点编号
    for (int i = 1; i < n; i++)
    {
        ji[now] = 1; //表示已加入
        int len = edges[now].size();
        for (int j = 0; j < len; j++) //尝试松弛相连节点
        {
            if (dis[now] + edges[now][j].val < dis[edges[now][j].next])
            {
                dis[edges[now][j].next] = dis[now] + edges[now][j].val;
                run.push(node{edges[now][j].next, dis[edges[now][j].next]}); //被更新,则可能作为下一个松弛点
            }
        }
        while (!run.empty() && ji[run.top().next]) //清空已加入点集的点
            run.pop();
        if(run.empty())
            break;
        now = run.top().next;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dis[i]);
    }
    return 0;
}