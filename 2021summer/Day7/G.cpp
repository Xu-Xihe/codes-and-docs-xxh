#include <cstdio>
#include <algorithm>
const int maxe = 15009;
int len;
long long ans[maxe], tree[maxe * maxe];
struct star
{
    int x, y;
} in[maxe];
bool cmp(star a, star b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
long long find(int x)
{
    long long ans = 0;
    for (; x > 0; x -= x & -x)
        ans += tree[x];
    return ans;
}
void add(int x)
{
    for (; x <= maxe * maxe - 3; x += x & -x)
        tree[x] += 1;
}
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d", &in[i].x, &in[i].y);
        in[i].x++;
        in[i].y++;
    }
    std::sort(in, in + len, cmp);
    for (int i = 0; i < len; i++)
    {
        long long lin = find(in[i].y);
        ans[lin]++;
        add(in[i].y);
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}