#include <cstdio>
const int maxe = 2e5 + 9;
int len, in[maxe], max;
long long tree[maxe], ans;
long long find(int x)
{
    long long ansl = 0;
    for (; x > 0; x -= x & -x)
        ansl += tree[x];
    return ansl;
}
void add(int x, int val)
{
    for (; x <= max; x += x & -x)
        tree[x] += val;
}
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &in[i]);
        if (in[i] > max)
            max = in[i];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        ans += find(in[i] - 1);
        //printf("ce:-->%d %d %d\n", i, in[i], find(in[i] - 1));
        add(in[i], 1);
    }
    printf("%lld", ans);
    return 0;
}