#include <cstdio>
#include <algorithm>
inline unsigned int Rand(unsigned int seed,unsigned int mod)
{
    seed ^= seed << 17, seed ^= seed >> 9, seed ^= seed << 23;
    return abs(seed) % mod;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    printf("%d", Rand(233,2321),Rand(2555,5353));
}