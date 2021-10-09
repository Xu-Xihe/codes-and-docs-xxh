#include <cstdio>
#include <algorithm>
using namespace std;
int len, tiao, start, endll;
int m[2005][3];
int bfs[105];
bool ji[105];
int minn(bool a[], int zhi[], int len)
{
    int small = 1e9;
    int ji = -1;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == 0 && zhi[i] < small)
        {
            small = zhi[i];
            ji = i;
        }
    }
    return ji;
}
void chu()
{
    for (int i = 0; i < 105; i++)
    {
        bfs[i] = 1e9;
    }
    for (int i = 0; i < 105; i++)
    {
        ji[i] = 0;
    }
}
/*void pr(int a[],bool b[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d %d\n",a[i],b[i]);
    }
}*/
int main()
{
    while (~scanf("%d%d", &len, &tiao))
    {
        chu();
        for (int i = 0; i < tiao; i++)
        {
            scanf("%d%d%d", &m[i][0], &m[i][1], &m[i][2]);
        }
        scanf("%d%d", &start, &endll);
        if (start == endll)
        {
            printf("0\n");
            continue;
        }
        int num = start;
        bfs[start] = 0;
        for (int a = 0; a < len; a++)
        {
            //printf("num=%d\n",num);
            for (int i = 0; i < tiao; i++)
            {
                if (m[i][0] == num)
                {
                    bfs[m[i][1]] = min(bfs[num] + m[i][2], bfs[m[i][1]]);
                }
                if (m[i][1] == num)
                {
                    bfs[m[i][0]] = min(bfs[num] + m[i][2], bfs[m[i][0]]);
                }
            }
            //pr(bfs,ji,len);
            //printf("\n\n\n");
            ji[num] = true;
            num = minn(ji, bfs, len);
        }
        if (bfs[endll] < 1e9)
            printf("%d\n", bfs[endll]);
        else
            printf("-1\n");
    }
}