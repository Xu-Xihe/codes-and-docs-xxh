#include <cstdio>
#include <iostream>
const int maxe = 5000;
int n, m, s, l, w[maxe][maxe];
int dis[maxe][maxe], aaa[maxe][maxe], left_ans = 1e9, right_ans = -1;
void things()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dis[i][j] = dis[i - 1][j] + dis[i][j - 1] - dis[i - 1][j - 1] + aaa[i][j];
}
bool check(int a)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (w[i][j] >= a)
                aaa[i][j] = 1;
            else
                aaa[i][j] = -1;
        }
    }
    things();
    for (int i = 1; i + s <= n; i++)
    {
        for (int j = 1; j + l <= m; j++)
        {
            int t = dis[i + s][j + l] + dis[i - 1][j - 1] - dis[i + s][j - 1] - dis[i - 1][j + l];
            if (t >= 0)
                return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &l);
    s--;
    l--;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &w[i][j]);
            left_ans = std::min(left_ans, w[i][j]);
            right_ans = std::max(right_ans, w[i][j]);
        }
    }
    while (left_ans < right_ans)
    {
        int mid = (left_ans + right_ans + 1) / 2;
        if (check(mid) == 1)
            left_ans = mid;
        else
            right_ans = mid - 1;
    }
    printf("%d", left_ans);
    return 0;
}