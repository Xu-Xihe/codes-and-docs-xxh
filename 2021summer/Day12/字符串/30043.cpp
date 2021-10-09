#include <cstdio>
const int maxe = 2000;
char aaa[maxe], b[maxe];
int next[maxe], ans,la,lb;
inline void gnext(char *in)
{
    next[0] = next[1] = 0;
    for (int i = 2; i < lb; i++)
    {
        int now = next[i - 1];
        while (now && in[now] != in[i - 1])
            now = next[now];
        //printf("next :  %d  %d  %d  %d\n", i, now, next[i - 1], next[now]);
        next[i] = in[i - 1] == in[now] ? now + 1 : 0;
    }
}
inline int strlen(char *p)
{
    for (int i = 0;; i++)
    {
        //printf("len   %d  : %c  %d\n", i, p[i], p[i]);
        if (p[i] == 0)
        {
            //printf("out  %d\n", i);
            return i;
        }
    }
}
int main()
{
    while (1)
    {
        scanf("%s", aaa);
        la = strlen(aaa);
        //printf("fjakjdflkajdfkljakldjflksajdfkljskf %d   ", la);
        if (la == 1 && aaa[0] == '#')
            return 0;
        scanf("%s", b);
        lb = strlen(b);
        gnext(b);
        ans = 0;
        //printf("cwdflka  %d  %d   %s   %s\n", la, lb, aaa, b);
        for (int i = 0, j = 0; i < la; i++)
        {
            //printf("ceshi  %d  %d  %d  %d  %d\n", i, j, aaa[i], b[j], ans);
            while (j && aaa[i] != b[j])
                j = next[j];
            if (aaa[i] == b[j])
                j++;
            if (j == lb)
                ans++;
        }
        printf("%d\n", ans);
    }
}