#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10010;
int w[4] = {1, 5, 10, 25}, t[N], f[N], pos[N], ans[N], c[5];
int main()
{
    int n, cnt = 1;
    while (~scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(pos, 0, sizeof(pos));
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < 4; i++)
            cin >> c[i];
        f[0] = 1;
        for (int i = 0; i < 4; i++)
        {
            memset(t, 0, sizeof(t));
            for (int j = 1; j <= n; j++)
            {
                if (t[j - w[i]] < c[i] && f[j - w[i]] && f[j] < (f[j - w[i]] + 1))
                {
                    f[j] = f[j - w[i]] + 1;
                    t[j] = t[j - w[i]] + 1;
                    pos[j] = j - w[i];
                }
            }
        }
        int find = n;
        if (f[find])
        {
            while (find)
            {
                ans[find - pos[find]]++;
                find = pos[find];
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", ans[w[0]], ans[w[1]], ans[w[2]], ans[w[3]], ans[w[4]]);
        }
        else
            printf("Charlie cannot buy coffee.\n");
    }
    return 0;
}
