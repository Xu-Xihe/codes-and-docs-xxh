#include <cstdio>
const int move[2][4] = {{1, 1, 2, 2}, {2, -2, 1, -1}};
int n, m, x_start, x_end, y_start, y_end;
long long ans;
void dfs(int x_now, int y_now)
{
    if (x_now == x_end && y_now == y_end)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int x_next = x_now + move[0][i], y_next = y_now + move[1][i];
        if(x_next<=0||y_next<=0||x_next>n||y_next>=m||x_next>x_end)continue;
        dfs(x_next, y_next);
    }
    return;
}
int main()
{
    scanf("%d%d%d%d%d%d", &n, &m, &x_start, &y_start, &x_end, &y_end);
    dfs(x_start, y_start);
    printf("%d", ans);
    return 0;
}