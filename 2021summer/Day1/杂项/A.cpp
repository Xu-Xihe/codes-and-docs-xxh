#include <cstdio>
#include <cmath>
int len, block, tag[250], num[50005];
int whick_block(int place)
{
    int max = len / block;
    int ans = place / block + 1;
    return ans > max ? 249 : ans;
}
int check(int place)
{
    return num[place] + tag[whick_block(place)];
}
void add(int start, int end, int much)
{
    while (start!=0 && start % block != 0&& start<=end)
    {
        num[start] += much;
        start++;
    }
    start--;
    while (start + block <= end)
    {
        start += block;
        tag[whick_block(start)] += much;
    }
    start++;
    while (start <= end)
    {
        num[start] += much;
        start++;
    }
    return;
}
int main()
{
    scanf("%d", &len);
    block = sqrt(len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < len; i++)
    {
        int opt, l, r, c;
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        if (opt)
            printf("%d\n", check(r-1));
        else
            add(l-1, r-1, c);
    }
    return 0;
}