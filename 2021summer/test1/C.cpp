#include <cstdio>
#include <queue>
const int maxe = 2e5 + 9;
int n, m, t, k, sweet[maxe], fa[maxe], out[maxe];
struct way
{
    int a, b, p;
    bool friend operator<(way a, way b)
    {
        return a.p < b.p;
    }
};
std::priority_queue<way> ways;
std::priority_queue<way> day;
std::priority_queue<int> taste[maxe];
std::queue<int> lin;
int find(int a)
{
    return fa[a] == a ? a : fa[a] = find(fa[a]);
}
void together(int a, int b)
{
    int x = find(a), y = find(b), z;
    if (x == y)
        return;
    /*if (taste[x].size() > taste[y].size())
    {
        z = x;
        x = y;
        y = x;
    }
    int aaa = taste[x].size();
    while (aaa--)
    {
        taste[y].push(taste[x].top());
        taste[x].pop();
    }*/
    fa[x] = y;
}
int main()
{
    //freopen("party.in","r",stdin);
    //freopen("party.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sweet[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        taste[i].push(sweet[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ways.push(way{a, b, c});
    }
    scanf("%d%d", &t, &k);
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        day.push(way{a, i, b});
    }
    for (int i = 0; i < t; i++)
    {
        int ans = 0;
        way time = day.top();
        day.pop();
        for (int j = 0; j < m; j++)
        {
            way min_way = ways.top();
            if (min_way.p < time.p)
                break;
            ways.pop();
            together(min_way.a, min_way.b);
        }
        int now = find(time.a);
        /*for (int i = 0; i < k; i++)
        {
            if(taste[now].empty())break;
            int linshi=taste[now].top();
            ans+=linshi;
            taste[now].pop();
            lin.push(linshi);
        }
        out[time.b]=ans;
        ans=lin.size();
        while (ans--)
        {
            taste[now].push(lin.front());
            lin.pop();
        }*/
        std::priority_queue<way> run;
        while (!run.empty())
            run.pop();
        for (int j = 1; j <= n; j++)
        {
            if (find(j) == now)
            {
                run.push(way{0, 0, sweet[j]});
                //printf("chu:-->%d\n",j);
            }
        }
        for (int j = 0; j < k; j++)
        {
            if (run.empty())
                break;
            ans += run.top().p;
            //printf("-->%d  ",run.top().p);
            run.pop();
        }
        out[time.b] = ans;
    }
    for (int i = 1; i <= t; i++)
    {
        printf("%d\n", out[i]);
    }
    return 0;
}