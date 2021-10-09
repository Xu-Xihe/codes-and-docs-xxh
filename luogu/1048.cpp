#include <cstdio>
#include <algorithm>
#define maxe 1000000
using namespace std;
int W, len, w[maxe], v[maxe], dp[maxe];
int main()
{
    scanf("%d%d", &W, &len);
    for (int i = 1; i <= len; i++)
    {
        scanf("%d%d", &w[i], &v[i]);
    }
    for (int i = 1; i <= len; i++)
    {
        for (int j = W; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[W]);
    //system("pause");
    return 0;
}