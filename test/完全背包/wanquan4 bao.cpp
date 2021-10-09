#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 0x3fffffff;
const int v[] = {0, 1, 5, 10, 25};
int c[10], w[10];
int dp[5][11000], flag[5][11000];

int main()
{
    int p, cnt;
    while (cin >> p >> c[1] >> c[2] >> c[3] >> c[4] && p + c[1] + c[2] + c[3] + c[4])
    {
        int T = 4;
        fill(dp[0], dp[5] - 1, -INF);
        memset(flag, 0, sizeof(flag));
        dp[0][0] = 0;
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 0; j <= p; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - v[i] >= 0)
                {
                    if (dp[i][j] < dp[i - 1][j - v[i]] + 1 && c[i] >= 1)
                    {
                        flag[i][j] = 1;
                        dp[i][j] = dp[i - 1][j - v[i]] + 1;
                    }
                    if (dp[i][j] < dp[i][j - v[i]] + 1 && flag[i][j - v[i]] + 1 <= c[i])
                    {
                        flag[i][j] = flag[i][j - v[i]] + 1;
                        dp[i][j] = dp[i][j - v[i]] + 1;
                    }
                }
            }
        }
        if (dp[4][p] < 0)
        {
            cout << "Charlie cannot buy coffee." << endl;
            continue;
        }
        memset(w, 0, sizeof(w));
        cnt = p;
        while (T)
        {
            w[T] = flag[T][cnt];
            cnt -= v[T] * w[T];
            T--;
        }
        printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", w[1], w[2], w[3], w[4]);
    }
    return 0;
}