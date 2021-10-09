#include <cstdio>
const int maxe = 3e6 + 9;
int len, in[maxe], next[maxe];
inline void gnext()
{
    next[0] = next[1] = 0;
    for (int i = 1; i < len; i++)
    {
        int now = next[i];
        while (now && in[now] != in[i])
            now = next[now];
        next[i + 1] = in[now] == in[i] ? now + 1 : 0;
    }
}
int main()
{
    //freopen("PF.in", "r", stdin);
    //freopen("PF.out", "w", stdout);
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &in[i]);
    }
    gnext();
    for (int i = 1; i <= len; i++)
    {
        int ans = i - next[i];
        //printf("ceshi %d  %d  %d  %d\n", i, next[i], ans);
        if (ans * 2 <= i)
            printf("%d\n", ans);
        else
            printf("0\n");
    }
    return 0;
}