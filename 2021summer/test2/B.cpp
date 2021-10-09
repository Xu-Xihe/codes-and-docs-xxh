#include <cstdio>
#include <algorithm>
#include <queue>
const int maxe = 1e5 + 9;
int in[maxe], ans, nodes[maxe],max;
bool biao[maxe];
struct node
{
    int x, y;
    bool friend operator<(node a, node b)
    {
        return a.y < b.y;
    }
};
std::priority_queue<node> ji;
inline int Lcs(int n, int *a, bool ord)
{ //下标从1开始
    int d[maxe],len = 0;
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        
        int bit = ord ? n + 1 - i : i;
        //printf("\nce:  %d  %d  %d  %d  %d   %d  %d\n", i, bit, len, a[bit], d[len],biao[bit],max);
        if(biao[bit]||a[bit]>=max)
            continue;
        if (a[bit] > d[len])
            d[++len] = a[bit]; //如果可以接在len后面就接上，如果是最长上升子序列，这里变成>
        else                 //否则就找一个最该替换的替换掉
        {
            int j = std::lower_bound(d + 1, d + len + 1, a[bit]) - d; //找到第一个大于它的d的下标，如果是最长上升子序列，这里变成lower_bound
            d[j] = a[bit];
        }
    }
    return len;
}
int main()
{
    //freopen("simple.in", "r", stdin);
    //freopen("simple.out", "w", stdout);
    int len;
    scanf("%d", &len);
    for (int i = 1; i <= len; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        nodes[a] = b;
        ji.push(node{a, nodes[a]});
    }
    for (int i = 0; i < len; i++)
    {
        if (ji.size() < ans)
            break;
        node a = ji.top();
        ji.pop();
        max = a.y;
        //printf("ceshi:  %d %d  %d  %d  %d %d   ", a.x, a.y,max, Lcs(a.x - 1, nodes, 0) ,Lcs(len, nodes + a.x, 1),ans);
        ans = std::max(ans, Lcs(a.x - 1, nodes, 0) + Lcs(len, nodes + a.x, 1));
        //printf("%d\n", ans);
        biao[a.x] = 1;
    }
    printf("%d", ans+1);
    return 0;
}