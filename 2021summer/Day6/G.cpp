#include <cstdio>
#include <queue>
const int maxn = 3e6 + 9;
int n, k, a[maxn];
struct one
{
    int a, wei;
};
std::deque<one> running;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        while (!running.empty() && running.front().wei <= i - k)
            running.pop_front();
        while (!running.empty() && running.back().a >= a[i])
            running.pop_back();
        running.push_back(one{a[i], i});
        if(i>=k-1)printf("%d ", running.front());
    }
    printf("\n");
    running.clear();
    for (int i = 0; i < n; i++)
    {
        while (!running.empty() && running.front().wei <= i - k)
            running.pop_front();
        while (!running.empty() && running.back().a <= a[i])
            running.pop_back();
        running.push_back(one{a[i], i});
        if(i>=k-1)printf("%d ", running.front());
    }
    return 0;
}