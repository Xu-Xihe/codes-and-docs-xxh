#include <cstdio>
void exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
}
int main()
{
    int aa, bb, xx, yy;
    scanf("%d%d%d%d", &aa, &bb, &xx, &yy);
    exgcd(aa, bb, xx, yy);
    printf("%d  %d", xx, yy);
}