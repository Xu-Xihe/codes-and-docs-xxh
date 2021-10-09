#include <cstdio>
#include <set>
#include <queue>
const unsigned int maxe = 3e5 + 9;
int n;
std::multiset<int> num;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int a, b, c;
        scanf("%d%d", &a, &b);
        if (a == 1)
        {
            num.insert(b);
        }
        if (a == 2)
        {
            num.erase(b);
        }
        if (a == 3)
        {
            scanf("%d", &c);
            if (c == 1)
            {
                int max = 0;
                for (int i:num)
                {
                    if(max>(b<<1)&&max>(i<<1))
                        break;
                    if(max<(i^b))
                        max = i ^ b;
                    //printf("ceshi :  %d  %d  %d\n", i, i ^ b, max);
                }
                printf("%d\n", max);
            }
            else
            {
                std::priority_queue<int> run;
                while (!run.empty())
                    run.pop();
                for (int i:num)
                {
                    run.push(i ^ b);
                }
                for (int i = 1; i < c; i++)
                    run.pop();
                printf("%d\n", run.top());
            }
        }
    }
    return 0;
}