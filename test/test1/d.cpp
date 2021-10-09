#include <cstdio>
#include <queue>
#include <cstring>
#define maxe 200
using namespace std;
char lao[maxe][maxe][maxe]; //l,r,c
bool ji[maxe][maxe][maxe];
int l, r, c, sl, sr, sc;
int nl[] = {0, 0, 0, 0, 1, -1};
int nr[] = {1, -1, 0, 0, 0, 0};
int nc[] = {0, 0, 1, -1, 0, 0};
struct id
{
    int l, r, c, ans;
};
bool isok(id in)
{
    if (in.l < 0 || in.c < 0 || in.r < 0 || in.l == l || in.c == c || in.r == r || ji[in.l][in.r][in.c] || lao[in.l][in.r][in.c] == '#')
    {
        return false;
    }
    return ji[in.l][in.r][in.c] = true;
}
queue<id> running;
int bfs()
{
    while (!running.empty())
    {
        id a = running.front();
        running.pop();
        //printf("%d    %d    %d\n\n",a.l,a.r,a.c);
        if (lao[a.l][a.r][a.c] == 'E')
            return a.ans;
        for (int i = 0; i < 6; i++)
        {
            id b;
            b.ans = a.ans + 1;
            b.c = a.c + nc[i];
            b.l = a.l + nl[i];
            b.r = a.r + nr[i];
            if (isok(b))
                running.push(b);
        }
    }
    return -1;
}
int main()
{
    while (~scanf("%d%d%d", &l, &r, &c))
    {
        if (l == 0 || r == 0 || c == 0)
            return 0;
        memset(ji, 0, sizeof(ji));
        while (!running.empty())
            running.pop();
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                scanf("%s", lao[i][j]);
                for (int z = 0; z < c; z++)
                {
                    if (lao[i][j][z] == 'S')
                    {
                        sl = i;
                        sr = j;
                        sc = z;
                    }
                }
            }
        }
        id a;
        a.ans = 0;
        a.c = sc;
        a.l = sl;
        a.r = sr;
        ji[sl][sr][sc]=true;
        running.push(a);
        int lin = bfs();
        if (lin == -1)
        {
            printf("Trapped!\n");
        }
        else
            printf("Escaped in %d minute(s).\n", lin);
    }
    return 0;
}