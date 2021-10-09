#include <stdio.h>
#include <string.h>
#include<algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
const int inf = 0x3f3f3f3f;
int n,nx, ny;
int lx[310], ly[310];
int visx[310], visy[310];
int slack[310];
int goal[310], weight[310][310];
int find(int x)

{
    visx[x] = 1;
    for (int j = 1; j <= ny; j++)
    {
        if (!visy[j])
        {
            int t = lx[x] + ly[j] - weight[x][j];
            if (t == 0)
            {
                visy[j] = 1;
                if (goal[j] == -1 || find(goal[j]))
                {
                    goal[j] = x;
                    return 1;
                }
            }
            else if (slack[j] > t)
                slack[j] = t;
        }
    }
    return 0;
}
int km()
{
    mem(ly, 0);
    mem(lx, 0);
    mem(goal, -1);
    for (int i = 1; i <= nx; i++) 
        for (int j = 1; j <= ny; j++)
            if (weight[i][j] > lx[i])
                lx[i] = weight[i][j];
    for (int i = 1; i <= nx; i++)
    {
        for (int j = 1; j <= ny; j++)
            slack[j] = inf;
        while (1)
        {
            mem(visx, 0);
            mem(visy, 0);
            if (find(i))
                break;
            int d = inf;
            for (int j = 1; j <= ny; j++)
                if (!visy[j] && d > slack[j])
                    d = slack[j];
            for (int j = 1; j <= ny; j++)
                if (!visy[j])
                    slack[j] -= d;
            for (int j = 1; j <= n; j++)

            {
                if (visy[j])
                    ly[j] += d;
                if (visx[j])
                    lx[j] -= d;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= ny; j++)
        if (goal[j] != -1)
            ans += weight[goal[j]][j];
    return ans;
}
int zhan_w[310], shang_w[310];
int main()
{
    //freopen("store.in", "r", stdin);
    //freopen("store.out", "w", stdout);
    scanf("%d%d", &nx, &ny);
    for (int i = 1; i <= nx; i++)
    {
        scanf("%d", &zhan_w[i]);
    }
    for (int i = 1; i <= ny; i++)
    {
        scanf("%d", &shang_w[i]);
    }
    for (int i = 1; i <= ny; i++)
    {
        for (int j = 1; j <= nx; j++)
        {
            int a;
            scanf("%d", &a);
            weight[i][j] = a * (shang_w[i] / zhan_w[j]);
        }
    }
    n = std::max(nx, ny);
    nx = ny = n;
    printf("%d\n", km());
    return 0;
}