#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using std::abs;
const int maxe = 2e5 + 9;
const long long INF = 922337203685477580;
int len;
long long ans, dis[maxe];
bool ji[maxe];
struct Nd
{
    int x, y, w;
};
struct R
{
    int id;
    long long val;
    bool friend operator<(R a, R b)
    {
        return a.val > b.val;
    }
};
std::vector<Nd> sda;
std::priority_queue<R> run;
inline long long far(Nd a, Nd b) //从a到b
{
    //printf("far   %lld   %lld  %lld  \n", abs(a.x - b.x), abs(a.y - b.y), b.w);
    return (long long)std::min(abs(a.x - b.x), abs(a.y - b.y)) + b.w;
}
void read(int &x)
{
    x = 0;
    char c = getchar(), d = 0;
    while (c < '0' || c > '9')
        d = c, c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + c - '0', c = getchar();
    if (d == '-')
        x = -x;
}
int main()
{
    //freopen("train.in", "r", stdin);
    //freopen("train.out", "w", stdout);
    read(len);
    sda.push_back(Nd{0, 0, 0});
    for (int i = 1; i <= len; i++)
    {
        Nd a;
        read(a.x);
        read(a.y);
        read(a.w);
        sda.push_back(a);
    }
    dis[1] = ans = sda[1].w;
    for (int i = 2; i <= len; i++)
    {
        dis[i] = INF;
    }
    run.push(R{1, ans});
    for (int i = 1; i < len; i++)
    {
        R top = run.top();
        run.pop();
        ji[top.id] = 1;
        //printf("ce shi  %d  :  %lld\n", top.id, top.val);
        for (int j = 1; j <= len; j++)
        {
            if (!ji[j])
            {
                long long cmp = top.val + far(sda[top.id], sda[j]);
                if (dis[j] > cmp)
                {
                    dis[j] = cmp;
                    run.push(R{j, cmp});
                }
                //printf("push in  %d    %lld   %lld\n", j, cmp, dis[j]);
            }
        }
        while (!run.empty() && ji[run.top().id])
            run.pop();
    }
    printf("%lld", dis[len]);
    return 0;
}