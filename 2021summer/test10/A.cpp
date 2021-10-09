#include <cstdio>
#include <algorithm>
const long long INF = 214748364700000000;
long long aa, bb, n, t1, t2, c1, c2, sss, szn, max, min;
bool xx, yy;
inline long long gcdEx(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    else
    {
        long long r = gcdEx(b, a % b, x, y);
        long long t = x;
        x = y;
        y = t - a / b * y;
        return r;
    }
}
inline void none(long long xi, long long chang, bool &big, long long &val)
{
    big = xi < 0 ? 0 : 1;
    chang *= -1;
    //double ans = (chang * (-1.0)) / xi;
    val = chang / xi;
    if (big && val >= 0 && (chang % xi) != 0)
        val++;
}
inline void put(long long p1, long long p2, long long s1, long long s2)
{
    if (p1 < 0)
        printf("%d %d", s1 + p1 * max, s2 + p2 * max);
    else
        printf("%d %d", s1 + p1 * min, s2 + p2 * min);
}
inline long long gcd(long long x, long long y)
{
    return y ? gcd(y, x % y) : x;
}
int main()
{
    long long t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &aa, &bb, &n);
        long long lin = gcdEx(aa, bb, c1, c2);
        if (n % lin != 0)
        {
            printf("-1\n");
            continue;
        }
        t1 = bb / lin;
        t2 = -aa / lin;
        c1 *= n / lin;
        c2 *= n / lin;
        none(t1, c1, xx, sss);
        none(t2, c2, yy, szn);
        if (xx == yy)
        {
            if (xx)
            {
                min = std::max(sss, szn);
                max = INF;
            }
            else
            {
                max = std::min(sss, szn);
                min = -INF;
            }
        }
        if (xx < yy)
            std::swap(sss, szn);
        if (xx != yy)
        {
            min = sss;
            max = szn;
        }
        if (min > max)
        {
            printf("-1\n");
            //continue;
        }
        //printf("%lld   %lld\n", min, max);
        put(t1, t2, c1, c2);
        printf(" ");
        put(t2, t1, c2, c1);
        printf("\n");
        //printf("x=%dt%c%d  y=%dt%c%d\n", t1, c1 >= 0 ? '+' : 0, c1, t2, c2 >= 0 ? '+' : 0, c2);
    }
}