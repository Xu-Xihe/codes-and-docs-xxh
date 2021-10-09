#include <cstdio>
#include <algorithm>
const int maxe = 1e4 + 5, changes[] = {0, 0, 1, 2, 6, 24, 120, 720,5040,40320,362880};
int m, len, finger[maxe];
int wei, num[maxe];
/*void out(int *group, int len)
{
    printf("\n\nce:");
    for (int i = 1; i <= len; i++)
    {
        printf("%d  ", group[i]);
    }
    printf("\n\n");
    return;
}*/
int front()
{
    int max = -100;
    for (int i = 1; i <= len; i++)
    {
        if (finger[i] > max)
            max = finger[i];
        if (changes[i] >= m && finger[i] < max)
            return i;
    }
}
int to_num(int order[])
{
    int ans = 0;
    for (int i = wei; i > 0; i--)
    {
        int cnt = 0;
        for (int j = 0; j < wei; j++)
        {
            if (order[j + 1] < finger[i])
                cnt++;
            if (order[j + 1] == finger[i])
                order[j + 1] = 1e9;
        }
        ans += cnt * changes[i];
    }
    return ans + 1;
}
void to_finger(int in)
{
    for (int i = wei; i > 0; i--)
    {
        if (in == 0)
        {
            //out(num,wei);
            std::sort(num + 1 , num + 1+wei);
            for (int i = wei; i >0 ; i--)
            {
                if (num[i] != 1e9)
                    printf("%d ", num[i]);
            }
            return;
        }
        std::sort(num + 1, num + 1 + wei);
        //out(num, wei);
        int cnt = in / changes[i];
        in %= changes[i];
        cnt += in > 0 ? 1 : 0;
        //printf("chu: %d %d %d  ", cnt, in, changes[i]);
        printf("%d ", num[cnt]);
        num[cnt] = 1e9;
    }
    return;
}
int main()
{
    scanf("%d%d", &len, &m);
    for (int i = len; i > 0; i--)
    {
        scanf("%d", &finger[i]);
    }
    wei = front();
    //out(finger, len);
    for (int i = len; i > wei; i--)
    {
        printf("%d ", finger[i]);
    }
    for (int i = 1; i <= wei; i++)
    {
        num[i] = finger[i];
    }
    std::sort(num + 1, num + wei + 1);
    //out(num, wei);
    int number = to_num(num);
    //printf("\nnumber-->%d\n", wei);
    number += m;
    for (int i = 1; i <= wei; i++)
    {
        num[i] = finger[i];
    }
    //out(num, wei);
    to_finger(number);
    return 0;
}