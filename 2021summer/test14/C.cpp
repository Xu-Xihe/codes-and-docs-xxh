#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
const int maxe = 20;
int n, m, l, r, ans;
struct N
{
    int id, val;
};
std::vector<N> next[maxe];
inline void dfs(int now, int val, std::bitset<20> ji)
{
    //printf("%d  %d  %d\n", now, val, ji.count());
    ji[now] = 1;
    if (val > r)
        return;
    if (now == 0 && val != 0)
    {
        if (val >= l && ji.count() == n+1)
            ans++;
    }
    for (auto i : next[now])
        dfs(i.id, val + i.val, ji);
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &l, &r);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        next[a].push_back(N{b, c});
        next[b].push_back(N{a, c});
    }
    dfs(0, 0, 0);
    printf("%d", ans);
}