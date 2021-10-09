#include <cstdio>
#include <vector>
const int maxn = 4e5 + 9, maxm = 2e5 + 9;
int n, m, fa[maxn], k, kill[maxn], ans[maxn];
bool ji[maxn];
std::vector<int> ways[maxn];
int find(int a)
{
    return fa[a] == a ? a : fa[a] = find(fa[a]);
}
void together(int a, int b)
{
    int x = find(a), y = find(b);
    fa[x] = y;
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + 5; i++)
    {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        ways[a].push_back(b);
        ways[b].push_back(a);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &kill[i]);
        ji[kill[i]] = true;
    }
    ans[k] = n - k;
    for (int i = 0; i < n; i++)
    {
        if (ji[i])
            continue;
        for (int j = 0; j < ways[i].size(); j++)
        {
            if (ji[ways[i][j]])
                continue;
            if (find(i) != find(ways[i][j]))
            {
                together(i, ways[i][j]);
                ans[k]--;
            }
        }
    }
    for (int i = k - 1; i >= 0; i--)
    {
        int alive = kill[i];
        ans[i] = ans[i + 1] + 1;
        ji[alive]=false;
        for (int j = 0; j < ways[alive].size(); j++)
        {
            if(ji[ways[alive][j]])continue;
            //printf("\n%d %d %d %d\n",i,j,alive,ways[alive][j]);
            if (find(alive) != find(ways[alive][j]))
            {
                together(alive, ways[alive][j]);
                ans[i]--;
            }
        }
    }
    for (int i = 0; i <= k; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}