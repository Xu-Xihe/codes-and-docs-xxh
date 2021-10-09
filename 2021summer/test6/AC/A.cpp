#include <cstdio>
#include <map>
#include <cmath>
int n, m, ans[300], a;
std::map<int, int> ji;
inline void change(int now)
{
    ans[ji[now]]--;
    ji[now]++;
    ans[ji[now]]++;
}
inline void more(int in)
{
    int len;
    len = std::min(int(sqrt(in)), n);
    for (int j = 1; j <= len; j++)
    {

        if (in % j == 0)
        {
            change(j);
            int lin = in / j;
            if (lin <= n && lin != j)
                change(lin);
        }
        //printf("one :%d  %d  %d\n", in[i], j, in[i] % j);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    ans[0] = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        more(a);
    }
    for (int i = 0; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}