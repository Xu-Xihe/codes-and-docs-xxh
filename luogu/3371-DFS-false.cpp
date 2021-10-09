#include <cstdio>
#include <vector>
const int maxe = 1e4 + 9;
struct node
{
    int next, val;
};
std::vector<node> edge[maxe];
int len, m, ans = 2e9, sta, end;
bool ji[maxe];
inline void dfs(int now, int val)
{
    if (val >= ans || now == end) //结束条件和一点点剪枝
    {
        ans = ans > val ? val : ans;
        return;
    }
    int n = edge[now].size();
    ji[now] = 1; //记录访问过的节点,防止环
    for (int i = 0; i < n; i++)
    {
        if (ji[edge[now][i].next]) //如果出现环,终止
            continue;
        dfs(edge[now][i].next, edge[now][i].val + val); //继续递归
    }
    ji[now] = 0; //访问归零
}
int main()
{
    scanf("%d%d%d%d", &len, &m, &sta, &end);
    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        edge[a].push_back(node{b, v});
    }
    dfs(sta, 0);
    printf("%d", ans);
    return 0;
}