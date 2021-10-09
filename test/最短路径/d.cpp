#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
#define maxe 500
using namespace std;
map<string, int> dollar;
int ld, len,ci;
double dp[maxe][maxe];
int main()
{
    while (~scanf("%d", &len))
    {
        if (len == 0)
            return 0;
        dollar.clear();
        for (int i = 0; i < len; i++)
        {
            string a;
            cin >> a;
            dollar[a] = i + 1;
        }
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j <= len; j++)
            {
                dp[i][j] = 1;
            }
        }
        scanf("%d", &ld);
        for (int i = 0; i < ld; i++)
        {
            string a, b;
            double c;
            cin >> a >> c >> b;
            dp[dollar[a]][dollar[b]] = c;
        }
        for (int zzz = 1; zzz <= len; zzz++)
        {
            for (int i = 1; i <= len; i++)
            {
                for (int j = 1; j <= len; j++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][zzz] * dp[zzz][j]);
                    //printf("%lf  ", dp[i][j]);
                }
                //printf("\n");
            }
        }
        bool out=false;
        for (int i = 1; i <= len; i++)
        {
            if (dp[i][i] > 1.0)
            {
                out = true;
                break;
            }
        }
        printf("Case %d: %s\n",++ci,out?"Yes":"No");
    }
    return 0;
}