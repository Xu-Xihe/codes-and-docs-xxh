#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;
int len, dist[100000];
struct node
{
    int id, valu;
    friend bool operator<(node a, node b)
    {
        return a.valu > b.valu;
    }
};
struct id
{
    int x, y;
} nodes[100000];
priority_queue<node> running;
int far(id a, id b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
vector<node> ways[3000];
void sfba()
{
    node a;
    a.valu = 0;
    dist[1] = 0;
    a.id = 1;
    running.push(a);
    //printf("fjlka");
    while (!running.empty())
    {
        node fi = running.top();
        running.pop();
        //printf("jal\n");
        int size = ways[fi.id].size();
        //printf("%d\n",size);
        for (int i = 0; i < size; i++)
        {
            //printf("%d --->%d\n",dist[fi.id] + ways[fi.id][i].valu,dist[ways[fi.id][i].id]);
            if ((dist[fi.id] + ways[fi.id][i].valu) < dist[ways[fi.id][i].id])
            {
                //printf("dlkfjal");
                dist[ways[fi.id][i].id] = dist[fi.id] + ways[fi.id][i].valu;
                //printf("jfdalaj\n");
                a.id = ways[fi.id][i].id;
                a.valu = dist[ways[fi.id][i].id];
                //printf("fjafalkj");
                running.push(a);
            }
            //printf("eirqpqir");
        }
    }
    printf("%d\n",dist[2]);
    printf("%.3f\n\n", sqrt(dist[2]));
    return;
}
int main()
{
    for (int iii = 1;; iii++)
    {
        scanf("%d", &len);
        if (len == 0)
            return 0;
        for (int i = 1; i <= len; i++)
        {
            dist[i] = 1e9;
            ways[i].clear();
        }
        while (!running.empty())
        {
            running.pop();
        }
        for (int i = 1; i <= len; i++)
        {
            scanf("%d%d", &nodes[i].x, &nodes[i].y);
        }
        for (int i = 1; i <= len; i++)
        {
            for (int j = i+1; j <= len; j++)
            {
                node lin;
                lin.id = j;
                lin.valu = far(nodes[i], nodes[j]);
                printf("%d %d\n",lin.id,lin.valu);
                ways[i].push_back(lin);
                //printf("%d===aaa===%d\n",i,ways[i].size());
                //printf("%d   %d |||%d---->%d\n",i,j,ways[i][j-2].id,ways[i][j-1].valu);
            }
        }
        printf("Scenario #%d\nFrog Distance = ", iii);
        sfba();
    }
    return 0;
}