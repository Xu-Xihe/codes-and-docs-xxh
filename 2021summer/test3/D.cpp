#include <cstdio>
#include <vector>
const int maxe = 309;
char type[23];
int len, ans, fa[maxe];
bool ji[maxe];
std::vector<int> next[maxe];
std::vector<int> root;
inline void ans_A(int now)
{
    int n = next[now].size();
    if (n == 0)
        return;
    ans += n - 1;
    for (int i = 0; i < n; i++)
    {
        ans_A(next[now][i]);
    }
}
inline void ans_B(int now)
{
    ji[now] = 1;
    int n = next[now].size();
    if (n == 0)
        return;
    bool first = 0;
    for (int i = 0; i < n; i++)
    {
        if (ji[next[now][i]])
        {
            if(next[fa[next[now][i]]].size()>1&&!first)
            {
                first = 1;
                ans--;
                fa[next[now][i]] = now;
            }
            continue;
        }
        if (first)
            ans++;
        else
            first = 1;
        fa[next[now][i]] = now;
        ans_B(next[now][i]);
    }
    printf("ce  %d  :  %d  \n", now, ans);
}
int main()
{
    freopen("DM.in", "r", stdin);
    freopen("DM.out", "w", stdout);
    scanf("%d%s", &len, type);
    for (int i = 1; i <= len; i++)
    {
        int n, a;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a);
            next[i].push_back(a);
            ji[a] = 1;
        }
    }
    for (int i = 1; i <= len; i++)
    {
        if (!ji[i])
            root.push_back(i);
        ji[i] = 0;
    }
    if (type[0] == 'A')
    {
        ans_A(root[0]);
        printf("%d", ans + 1);
        return 0;
    }
    if (type[0] == 'B')
    {
        int n = root.size();
        for (int i = 0; i < n; i++)
        {
            ans_B(root[i]);
        }
        printf("%d", ans + n);
    }
    return 0;
}