#include <cstdio>
const int maxe = 300;
int len, in[maxe], dp[maxe][maxe];
inline void add(int x, int val)
{
    for (; x <= len * 2; x += x & -x)
        in[x] += val;
}
inline int sum(int x)
{
    int ans = 0;
    for (; x > 0; x -= x & -x)
        ans += in[x];
    return ans;
}
int max(int a, int b)
{
    return a < b ? b : a;
}
int min(int a,int b)
{
    return a < b ? a : b;
}
inline int ansd(int cmp(int a, int b))
{
    int ans = -cmp(-2e9, 2e9),fir=ans;
    for (int i = 2; i <= len; i++) // long
    {
        for (int j = 1; j <= len * 2 - i + 1; j++) //start
        {
            int last = i + j - 1;
            dp[j][last] = fir;
            for (int k = j; k < last; k++)
            {
                dp[j][last] = cmp(dp[j][k] + dp[k + 1][last], dp[j][last]);
            }
            dp[j][last] += sum(last) - sum(j - 1);
            if (i == len)
                ans = cmp(dp[j][last], ans);
        }
    }
    return ans;
}
int main()
{
    scanf("%d", &len);
    for (int i = 1; i <= len; i++)
    {
        int a;
        scanf("%d", &a);
        add(i, a);
        add(i + len, a);
    }
    printf("%d\n%d\n", ansd(min),ansd(max));
    return 0;
}