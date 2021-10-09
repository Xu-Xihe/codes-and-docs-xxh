#include <cstdio>
struct point
{
    int x, y;
} B, C;
long long chu[30][30];
const int ma[2][9] = {{1, 1, -1, -1, 2, 2, -2, -2, 0},
                      {-2, 2, 2, -2, -1, 1, 1, -1, 0}},
          next[2][2] = {{0, 1}, {1, 0}};
bool fall(int x, int y)
{
    if (x == 1 && y == 1)
        return false;
    return x >= 1 && x <= B.x && y >= 1 && y <= B.y ? true : false;
}
int main()
{
    scanf("%d%d%d%d", &B.x, &B.y, &C.x, &C.y);
    B.x++;
    B.y++;
    C.x++;
    C.y++;
    chu[1][1] = 1;
    for (int i = 0; i < 9; i++)
    {
        if (fall(C.x + ma[0][i], C.y + ma[1][i]))
            chu[C.x + ma[0][i]][C.y + ma[1][i]] = -1;
    }
    for (int i = 1; i <= B.x; i++)
    {
        for (int j = 1; j <= B.y; j++)
        {
            if (chu[i][j] < 0)
                continue;
            chu[i][j] += chu[i - 1][j] > 0 ? chu[i - 1][j] : (long long)0;
            chu[i][j] += chu[i][j - 1] > 0 ? chu[i][j - 1] : (long long)0;
            //printf("ce:%d %d %d %d ans=%d\n\n",i-1,j-1,chu[i-1][j],chu[i][j-1],chu[i][j]);
        }
    }
    /*for (int i = 0; i < B.x; i++)
    {
        for (int j = 0; j < B.y; j++)
        {
            printf("%d  ",chu[i+1][j+1]);
        }
        printf("\n\n");
    }*/
    printf("%lld\n", chu[B.x][B.y] > 0 ? chu[B.x][B.y] : 0);
    return 0;
}