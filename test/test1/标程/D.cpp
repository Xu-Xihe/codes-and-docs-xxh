#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define InBox(x, upx) (x >= 0 && x < upx)
using namespace std;
const int maxn = 40;
char wheres[maxn][maxn][maxn];
int L, R, C;
int dirL[6] = {0, 0, 0, 0, -1, 1};
int dirR[6] = {0, 0, 1, -1, 0, 0};
int dirC[6] = {1, -1, 0, 0, 0, 0};
struct node
{
    int L, R, C;
    int dep;
};
bool isInBox(node tmp)
{
    if (wheres[tmp.L][tmp.R][tmp.C] == 0 || wheres[tmp.L][tmp.R][tmp.C] == '#')
        return false;
    if (InBox(tmp.L, L) && InBox(tmp.C, C) && InBox(tmp.R, R))
    {
        wheres[tmp.L][tmp.R][tmp.C] = 0;
        return true;
    }
    return false;
}
int bfs(node sn, node en)
{
    queue<node> que;
    sn.dep = 0;
    wheres[sn.L][sn.R][sn.C] = 0;
    que.push(sn);
    while (!que.empty())
    {
        node tmp = que.front();
        que.pop();
        int nL = tmp.L;
        int nR = tmp.R;
        int nC = tmp.C;
        int dep = tmp.dep + 1;
        if (nL == en.L && nR == en.R && nC == en.C)
            return dep - 1;
        for (int i = 0; i < 6; i++)
        {
            tmp.L = nL + dirL[i];
            tmp.R = nR + dirR[i];
            tmp.C = nC + dirC[i];
            tmp.dep = dep;
            if (isInBox(tmp))
                que.push(tmp);
        }
    }
    return -1;
}
int main()
{
    while (~scanf("%d%d%d", &L, &R, &C))
    {
        if (!(L || R || C))
            break;
        node sn, en;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < R; j++)
            {
                scanf("%s", wheres[i][j]);
                for (int k = 0; k < C; k++)
                {
                    if (wheres[i][j][k] == 'S')
                    {
                        sn.L = i;
                        sn.R = j;
                        sn.C = k;
                    }
                    if (wheres[i][j][k] == 'E')
                    {
                        en.L = i;
                        en.R = j;
                        en.C = k;
                    }
                }
            }
        int ans = bfs(sn, en);
        if (ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);
    }
}