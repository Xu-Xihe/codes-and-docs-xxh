#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[200], in[200][5], now, len;
void pan(int a, int b, int i)
{ //a为举起，b为放下
    if (a == b)
    {
        now = 0;
        dp[i] = a;
    }
    else if (a > b)
    {
        now = 2;
        dp[i] = b;
    }
    else
    { //a<b
        now = 1;
        dp[i] = a;
    }
    /*for (int i = 1; i <= len; i++)
    {
        printf("%d  ",dp[i]);
    }
    printf("\n\n\n");*/
    return;
}
int main()
{
    while (~scanf("%d", &len))
    {
        memset(dp, 0, sizeof(dp));
        now = 2;
        for (int i = 1; i <= len; i++)
        {
            scanf("%d%d%d", &in[i][1], &in[i][2], &in[i][3]);
        }
        for (int i = 1; i <= len; i++)
        { //1举起，2放下，3均可
            int last = dp[i - 1];
            //printf("%d--->%d\n",i,last);
            if (now == 1)
            {
                int a = last + in[i][1], b = last + in[i][2] + in[i][3];
                pan(a, b, i);
            }
            else if (now == 2)
            {
                int a = last + in[i][1] + in[i][3], b = last + in[i][2];
                pan(a, b, i);
            }
            else if (now == 0)
            {
                int a = last + in[i][1], b = last + in[i][2];
                pan(a, b, i);
            }
        }
        printf("%d\n", dp[len]);
    }
    return 0;
}