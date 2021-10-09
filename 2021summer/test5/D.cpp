#include <cstdio>
#include <set>
#include <algorithm>
using std::abs;
const int maxe = 2e6 + 9;
struct mon
{
    int h, x, y;
    bool friend operator<(mon a, mon b)
    {
        return a.h > b.h;
    }
} szn[maxe];
std::multiset<mon> ans;
int tot, q, last;
inline int add(mon ne)
{
    szn[++tot] = ne;
    for (int i = 1; i <= tot; i++)
    {
        ans.insert(mon{abs(szn[i].x - ne.x) + abs(szn[i].y - ne.y) + ne.h, i, tot});
    }
}
inline int ask(int out)
{
    for (auto i : ans)
    {
        //printf("shi  %d  %d   %d\n", i.x, i.y, out);
        if (i.x != out && i.y != out)
            return i.h;
    }
}
void show()
{
    printf("\nshow:\n");
    int a = 1;
    for (auto i : ans)
    {
        printf("ceshi   %d :   %d  %d  %d\n", a, i.h, i.x, i.y);
        a++;
    }
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
    //freopen("rest.out", "w", stdout);
    //freopen("rest.in", "r", stdin);
    read(q);
    int type, x, y, h;
    while (q--)
    {
        read(type);
        if (type == 1)
        {
            read(x);
            read(y);
            read(h);
            x ^= last;
            y ^= last;
            h ^= last;
            add(mon{h, x, y});
            //show();
        }
        if (type == 2)
        {
            last = ask(0);
            printf("%d\n", last);
            last %= 3;
        }
        if (type == 3)
        {
            read(x);
            last = ask(x);
            printf("%d\n", last);
            last %= 3;
        }
    }
    return 0;
}