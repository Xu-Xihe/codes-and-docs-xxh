#include <cstdio>
#define ll unsigned long long
const ll mode = 998244353;
ll pow(ll a, ll b, ll m)
{
    ll ans = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;
}
ll inv(ll x, ll p)
{
    return pow(x, p - 2, p);
}
ll C(ll n, ll m, ll p)
{
    if (m > n)
        return 0;
    ll up = 1, down = 1;
    for (int i = n - m + 1; i <= n; i++)
        up = up * i % p;
    for (int i = 1; i <= m; i++)
        down = down * i % p;
    return up * inv(down, p) % p;
}
ll Lucas(ll n, ll m, ll p)
{
    if (m == 0)
        return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
int n, m, a, b, c, x, y, mina, minb, maxt;
ll ans = 1;
int main()
{
    scanf("%d%d%d%d%d%d%d", &n, &m, &a, &b, &c, &x, &y);
    mina = y - b > 0 ? x - (c - (y - b)) : x - c;
    minb = x - a > 0 ? y - (c - (x - a)) : y - c;
    maxt = (n - x - y) - (m - x - y);
    ans = Lucas(n, m, mode);
    for (int i = maxt + 1; i <= n - x - y; i++)
        ans -= Lucas(n - x - y, i, mode);
    for (int i = x - c; i < mina; i++)
        ans -= Lucas(a, i, mode);
    for (int i = y - c; i < minb; i++)
        ans -= Lucas(b, i, mode);
    while (ans < 0)
        ans += mode;
    printf("%lld", ans);
    return 0;
}