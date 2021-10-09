#include <cstdio>
long long l, r;
int main()
{
    freopen("young.in", "r", stdin);
    freopen("young.out", "w", stdout);
    scanf("%lld%lld", &l, &r);
    printf("%lld\n%lld\n%lld\n%lld", l == r ? l : 1, r, l, r == l ? l : r * (r - 1));
}