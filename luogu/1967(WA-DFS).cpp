#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
int n, m;
const int maxe = 10009;
std::vector<int> fa;
std::vector<short int> point[maxe];
std::queue<short int> single;
std::vector<short int> nodes;
bool ji[maxe];
int edge[maxe][maxe];
struct way
{
    int city1, city2, weigh;
    bool friend operator<(way a, way b)
    {
        return a.weigh < b.weigh;
    }
};
struct node
{
    int next, weigh;
};
std::priority_queue<way> ways;
//std::queue<way> chosen;
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void together(int a, int b)
{
    int x = find(a), y = find(b);
    fa[x] = y;
    return;
}
void dfs(int now, int last)
{
    printf("\n\nchu:  %d  %d\n\n",now,last);
    int len = nodes.size();
    for (int i = 0; i < len; i++)
    {
        int least = edge[nodes[i]][last] < edge[last][now] ? edge[nodes[i]][last] : edge[last][now];
        edge[nodes[i]][now] = least;
        edge[now][nodes[i]] = least;
    }
    if (point[now].size() == 1)
        return;
    nodes.push_back(last);
    for (int i = 0; i < point[now].size(); i++)
    {
        if(point[now][i]!=last)dfs(point[now][i],now);
    }
}
void out()
{
    printf("\n\nceshi:\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%10d  ", edge[i + 1][j + 1]);
        }
        printf("\n\n");
    }
    printf("\n\n");
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + 9; i++)
    {
        fa.push_back(i);
        for (int j = 0; j < n + 9; j++)
        {
            edge[i][j] = 2e9;
        }
    }
    for (int i = 0; i < m; i++)
    {
        way in;
        scanf("%d%d%d", &in.city1, &in.city2, &in.weigh);
        ways.push(in);
    }
    for (int i = 0; i < m; i++)
    {
        way top = ways.top();
        ways.pop();
        if (find(top.city1) != find(top.city2))
        {
            together(top.city1, top.city2);
            //chosen.push(top);
            point[top.city1].push_back(top.city2);
            point[top.city2].push_back(top.city1);
            edge[top.city1][top.city2] = top.weigh;
            edge[top.city2][top.city1] = top.weigh;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (point[i + 1].size() == 1 && !ji[find(i + 1)])
        {
            single.push(i + 1);
            ji[find(i + 1)] = true;
        }
    }
    fa.clear();
    int len = single.size();
    for (int i = 0; i < len; i++)
    {
        dfs(point[single.front()][0], single.front());
        single.pop();
    }
    out();
    int le;
    scanf("%d", &le);
    for (int i = 0; i < le; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", edge[a][b] == 2e9 ? -1 : edge[a][b]);
    }
    return 0;
}