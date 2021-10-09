#include <cstdio>
#include <algorithm>
#define ll unsigned long long
//#define IO(x) freopen(x ".in", "r", stdin);freopen(x ".out", "w", stdout);
int t, p, now;
ll ans = 1;
struct Q
{
    int id;
    ll n;
} ask[2000];
ll gcd(ll x, ll y)
{
    return y ? gcd(y, x % y) : x;
}
inline bool cmp(Q a, Q b)
{
    return a.n < b.n;
}
inline bool out(Q a, Q b)
{
    return a.id < b.id;
}
inline void net(ll &last, ll sta, ll end)
{
    for (int i = sta; i <= end; i++)
    {
        for (int j = 1; j < sta; j++)
        {
            ll lin = gcd(j, i) % p;
            last *= lin;
            last %= p;
            last *= lin;
            last %= p;
        }
        last *= gcd(i, i) % p;
        last %= p;
    }
}
int main()
{
    // IO()
    scanf("%d%d", &t, &p);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &ask[i].n);
        ask[i].id = i;
    }
    std::sort(ask, ask + t, cmp);
    for (int i = 0; i < t; i++)
    {
        net(ans, now + 1, ask[i].n);
        now = ask[i].n;
        ask[i].n = ans;
    }
    std::sort(ask, ask + t, out);
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", ask[i].n);
    }
    return 0;
}