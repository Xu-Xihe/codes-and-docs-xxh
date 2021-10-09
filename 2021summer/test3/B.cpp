#include <cstdio>
#include <cstring>
using std::strlen;
const int maxe = 3e6 + 500;
int n, next[maxe];
char in[maxe];
void getnext(char P[], int f[])
{
    int m = strlen(P);
    f[1] = f[2] = 1;
    for (int i = 2; i <= m; i++)
    {
        int j = f[i];
        while (j>1 && P[i] != P[j])
            j = f[j];
        f[i + 1] = P[i] == P[j] ? j + 1 : 0;
    }
}
int main()
{
    //freopen("PF.in", "r", stdin);
    //freopen("PF.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char a;
        while (1)
        {
            scanf("%c", &a);
            if (a >= '0' && a <= '9')
                break;
        }
        in[i] = a;
        printf("in:  %d  %d\n", i, a);
    }
    getnext(in, next);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", next[n + 1]);
    }  
    for (int i = 1; i <= n; i++)
    {
        int ans = i - next[i];
        printf("ce:  %d  %d  %d\n", i, ans, next[ans]);
        if(next[ans]*2==ans)
            printf("%d\n", ans / 2);
        else
            printf("0\n");
    }
}