#include<cstdio>
#include<algorithm>
int len;
long long ans[200009];
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &ans[i]);
    }
    std::sort(ans, ans + len);
    long long now = ans[0];
    int out = 1;
    for (int i = 1; i <= len; i++)
    {
        if(ans[i]==now)
        {
            out++;
            continue;
        }
        printf("%d %d\n", now, out);
        now = ans[i];
        out = 1;
    }
    return 0;
}