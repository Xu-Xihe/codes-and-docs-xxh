#include <cstdio>
#include <unordered_map>
#include <algorithm>
const int maxe = 1e5 + 9;
int n, in[maxe], tot, szn[maxe], big;
unsigned int ans[5000000];
std::unordered_map<unsigned int, unsigned int> num;
inline double out()
{
    long long a = 0, b = 0;
    double abc = 0;
    for (int i = 1; i <= n; i++)
    {
        a += i;
        //printf("zhong ::  %d  %d  %d\n", big, ans[big], b);
        if (big > 0)
            b += ans[big] * big;
        big--;
    }
    while (big > 0)
    {
        b += ans[big] * big;
        big--;
    }
    //printf("fdasfk;ladfkjalkdfjlksajdflksajd :    %d    %d \n", a, b);
    return (double)b / a;
}
void pri()
{
    printf("\n\n");
    for (int i = 0; i < tot; i++)
    {
        printf("%d  ", in[i + 1]);
    }
    printf("\n");
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        unsigned int a;
        scanf("%lld", &a);
        szn[i] = num[a];
        if (szn[i] == 0)
        {
            szn[i] = ++tot;
            num[a] = tot;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int all = 0;
        for (int j = 1; j <= tot; j++)
            in[j] = 0;
        for (int j = 1; j <= i; j++)
        {
            all += in[szn[j]]++;
        }
        ans[all]++;
        big = std::max(big, all);
        //printf("ceshi  %3d  %3d  %3d   %3d   %3d\n", 1, i, i, all, ans[all]);
        for (int j = 2; j <= n - i + 1; j++)
        {
            int end = j + i - 1;
            // pri();
            all -= --in[szn[j - 1]];
            all += in[szn[end]]++;
            ans[all]++;
            // pri();
            big = std::max(big, all);
            //printf("ceshi  %3d  %3d  %3d  %3d  %3d\n", j, end, i, all, ans[all]);
        }
    }
    printf("%.6f", out());
    return 0;
}