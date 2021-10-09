#include <cstdio>
#include <algorithm>
#include <cmath>
const int maxe = 300, me = 1e5;
int n, m, in[maxe];
int ji[me];
using std::sqrt;
inline void one()
{
    int ans = 0, len = std::min(int(sqrt(in[1])), n);
    for (int i = 1; i <= len; i++)
    {
        //printf("one :%d  %d  %d  %d\n", in[1], i, in[1] % i, ans);
        if (in[1] % i == 0)
            ans += in[1] / i <= n && in[1] / i != i ? 2 : 1;
    }
    printf("%d\n%d\n", n - ans, ans);
}
inline void more()
{
    int len;
    for (int i = 1; i <= m; i++)
    {
        len = std::min(int(sqrt(in[i])), n);
        for (int j = 1; j <= len; j++)
        {

            if (in[i] % j == 0)
            {
                ji[j]++;
                int lin = in[i] / j;
                if (lin <= n && lin != j)
                    ji[lin]++;
            }
            //printf("one :%d  %d  %d\n", in[i], j, in[i] % j);
        }
    }
}
void show()
{
    for (int j = 0; j < n; j++)
    {
        printf("%d  ", ji[j + 1]);
    }
}
int main()
{
    freopen("div.in", "r", stdin);
    freopen("div.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &in[i]);
    }
    if (m == 1)
    {
        one();
        return 0;
    }
    else
    {
        more();
        int ans = 0;
        for (int i = 0; i <= m; i++, ans = 0)
        {
            for (int j = 1; j <= n; j++)
            {
                if (ji[j] == i)
                    ans++;
            }
            printf("%d\n", ans);
        }
        //show();
        return 0;
    }
}