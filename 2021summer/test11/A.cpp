#include <cstdio>
const int mode = 998244353;
int n, k, in[50];
inline int mi(int n, int m, int mod, long long sum = 1, long long ans = 1)
{
    if(m==0)
        return 1;
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
    return ans % mod;
}
inline long long it(int n)
{
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += in[i] * mi(n, i, mode);
        ans &= mode;
    }
    return ans;
}
long long fib(int n)
{
    if (n <= 0)
        return 0+it(0);
    else if (n == 1)
        return 1+it(1);
    else
        return (fib(n - 1) + fib(n - 2)) % mode+it(n);
}
int main()
{
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &in[i]);
    }
    printf("%lld\n", fib(n)%mode);
}