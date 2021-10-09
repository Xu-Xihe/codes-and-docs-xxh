#include <cstdio>
#include <cstring>
const int maxe = 4e5 + 9;
int next[maxe], len;
char in[maxe];
inline void gnext()
{
    next[0] = next[1] = 0;
    for (int i = 1; i < len; i++)
    {
        int now = next[i];
        while (now && in[now] != in[i])
            now = next[now];
        next[i + 1] = in[i] == in[now] ? now + 1 : 0;
    }
}
inline void ans(int now)
{
    if (now == 0)
        return;
    ans(next[now]);
    printf("%d ", now);
}
int main()
{
    while (~scanf("%s", in))
    {
        len = strlen(in);
        gnext();
        ans(len);
        printf("\n");
    }
    return 0;
}