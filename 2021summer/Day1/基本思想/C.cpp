#include <cstdio>
#include <algorithm>
int len, m, cow, num_cow[300];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    scanf("%d%d%d", &m, &len, &cow);
    for (int i = 0; i < cow; i++)
    {
        scanf("%d", &num_cow[i]);
    }
    std::sort(num_cow, num_cow + cow);
    len-=num_cow[0]-1+(len-num_cow[cow-1]);
    for (int i = 0; i < cow - 1; i++)
    {
        num_cow[i] = num_cow[i + 1] - num_cow[i];
    }
    num_cow[cow - 1] = 0;
    std::sort(num_cow, num_cow + cow, cmp);
    for (int i = 0; i < m - 1 && i < cow-1; i++)
    {
        len -= num_cow[i]-1;
        //printf("ce: i-->%d cow[i]-->%d len-->%d\n", i, num_cow[i],len);
    }
    printf("%d", len);
    return 0;
}