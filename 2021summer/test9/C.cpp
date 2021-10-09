#include <cstdio>
const long long mode = 20011021;
long long n, k, n1;
inline unsigned long long mi(long long n, long long m, long long mod, unsigned long long sum = 1, unsigned long long ans = 1)
{
    sum = n;
    while (m)
    {
        if (m & 1)
        {
            ans *= sum;
            ans %= mod;
        }
        sum *= sum;
        sum %= mod;
        m >>= 1;
    }
    return ans;
}
int main()
{
    //freopen("corn.in", "r", stdin);
    //freopen("corn.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    n1 = n;
    n %= mode - 1;
    long long ans = mi(k - 1, n, mode);
    ans += n1 % 2 == 0 ? k - 1 : 1 - k;
    if (ans < 0)
        ans += mode;
    printf("%lld", ans % mode);
    return 0;
}