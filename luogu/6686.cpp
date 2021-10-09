#include <cstdio>
#include <queue>
const int maxe = 2e5 + 9;
const long long mode = 998244353;
int len, n;
long long edge[maxe], ans, in[maxe];
std::queue<int> yao;
int lgt(int x)
{
    return x * 2 > len ? len : x * 2 - 1;
}
void mod(long long&a)
{
    long long lin = a / mode;
    a -= mode * lin;
}
long long other(int x)
{
    long long re = (in[x] * in[x]-in[x])/2;
    mod(re);
    re *= edge[lgt(x)] - in[x];
    mod(re);
    return re;
}
long long same(int x)
{
    long long re = ((in[x] - 2) * (in[x] - 1) * in[x]) / 6;
    mod(re);
    return re;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        in[a]++;
        if (in[a] == 2)
            yao.push(a);
        if (a > len)
            len = a;
    }
    for (int i = 1; i <= len; i++)
    {
        edge[i] = in[i] + edge[i - 1];
    }
    n = yao.size();
    while (n--)
    {
        int now = yao.front();
        yao.pop();
        ans += other(now);
        mod(ans);
        ans += same(now);
        mod(ans);
    }
    printf("%lld", ans);
    return 0;
}