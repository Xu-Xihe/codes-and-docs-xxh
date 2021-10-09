#include <cstdio>
#include <map>
#include <vector>
const int maxm = 2e6 + 5;
int len, n, fa[maxm], bian;
std::map<int, long long> nodes;
struct tap
{
    int i, j;
};
std::vector<tap> unsame;
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
    scanf("%d", &len);
    while (len--)
    {
        bool ans = true;
        scanf("%d", &n);
        unsame.clear();
        nodes.clear();
        bian = 1;
        for (int z = 0; z < n; z++)
        {
            int i, j, e;
            scanf("%d%d%d", &i, &j, &e);
            if (!nodes.count(i))
            {
                nodes[i] = bian;
                fa[bian] = bian;
                i = bian++;
            }
            else
                i = nodes[i];
            if (!nodes.count(j))
            {
                nodes[j] = bian;
                fa[bian] = bian;
                j = bian++;
            }
            else
                j = nodes[j];
            if (e)
            {
                together(i, j);
            }
            else
            {
                tap ddd;
                ddd.i = i;
                ddd.j = j;
                unsame.push_back(ddd);
            }
        }
        int lena = unsame.size();
        for (int i = 0; i < lena; i++)
        {
            if (find(unsame[i].i) == find(unsame[i].j))
            {
                ans = false;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}