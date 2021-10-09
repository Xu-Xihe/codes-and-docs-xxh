#include <cstdio>
struct point
{
    int x, y;
};
point B, C;
int ans;
const int ma[2][9] = {{1, 1, -1, -1, 2, 2, -2, -2, 0},
                      {-2, 2, 2, -2, -1, 1, 1, -1, 0}},
          next[2][2] = {{0, 1}, {1, 0}};
bool ma_leg(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        //printf("ma:%d %d\n",C.x+ma[0][i],C.y+ma[1][i]);
        if (C.x + ma[0][i] == x && C.y + ma[1][i] == y)
            return true;
    }
    return false;
}
bool fall(int x, int y)
{
    return x >= 0 && x <= B.x && y >= 0 && y <= B.y ? true : false;
}
void chu(int x, int y)
{
    if (B.x == x && y == B.y)
    {
        ans++;
        //printf("fajflk\n\n");
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int n_x = x + next[0][i], n_y = y + next[1][i];
        //printf("che:%d %d\n\n",n_x,n_y);
        if (fall(n_x, n_y) && !ma_leg(n_x, n_y))
            chu(n_x, n_y);
    }
    return;
}
int main()
{
    scanf("%d%d%d%d", &B.x, &B.y, &C.x, &C.y);
    chu(0, 0);
    printf("%d\n", ans);
    return 0;
}