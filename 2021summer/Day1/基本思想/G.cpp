#include <cstdio>
#include <algorithm>
#include <bitset>
int n, h, ans;
std::bitset<(int)3e4 + 9> ji;
struct que
{
    int sta, end, t;
} ask[6000];
inline bool cmp(que a, que b)
{
    return a.end < b.end;
}
inline int add(que in)
{
    int lin = 0;
    for (int i = in.end; i >= in.sta; i--)
    {
        if (ji[i])
            lin++;
    }
    lin = in.t - lin;
    if (lin <= 0)
        return 0;
    for (int i = in.end, j = lin; i >= in.sta && j > 0; i--)
    {
        if (!ji[i])
        {
            j--;
            ji[i] = 1;
        }
    }
    return lin;
}
int main()
{
    scanf("%d%d", &n, &h);
    for (int i = 0; i < h; i++)
    {
        scanf("%d%d%d", &ask[i].sta, &ask[i].end, &ask[i].t);
    }
    std::sort(ask, ask + h, cmp);
    for (int i = 0; i < h; i++)
    {
        ans += add(ask[i]);
    }
    printf("%d\n", ans);
    return 0;
}