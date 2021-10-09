#include <cstdio>
#include <cstring>
int num[2][5000], len[2], big, mine, maxe, top;
int cmp(int *a, int *b, int start)
{
    for (int i = start - 1; i >= 0; i--)
    {
        if (a[i] > b[i])
            return 0;
        if (a[i] < b[i])
            return 1;
    }
    return -1;
}
int chang(int *num, char *str, int str_len)
{
    int num_bit, zero, zero_bit;
    for (int i = str_len - 1; i >= 0; i--)
    {
        num_bit = (str_len - 1 - i) / 9;
        zero_bit = (str_len - 1 - i) % 9;
        zero = 1;
        for (int cnt = 0; cnt < zero_bit; cnt++)
        {
            zero *= 10;
        }
        num[num_bit] += (str[i] - '0') * zero;
    }
    return num_bit + 1;
}
void put_in(int a)
{
    char in[18600];
    int str_len;
    scanf("%s", in);
    str_len = strlen(in);
    len[a] = chang(num[a], in, str_len);
}
int main()
{

    put_in(0);
    put_in(1);
    maxe = len[0] < len[1] ? len[1] : len[0];
    big = cmp(num[0], num[1], maxe);
    mine = len[0] < len[1] ? len[0] : len[1];
    if (big == -1)
    {
        printf("0");
        return 0;
    }
    for (int i = 0; i < mine; i++)
    {
        num[big][i] -= num[!big][i];
        if (num[big][i] < 0)
        {
            num[big][i + 1]--;
            num[big][i] += 1e9;
        }
    }
    for (int i = maxe - 1; i >= 0; i--)
    {
        if (num[big][i] != 0)
        {
            top = i;
            break;
        }
    }
    if (big)
        printf("-");
    printf("%d", num[big][top]);
    for (int i = top - 1; i >= 0; i--)
    {
        printf("%09d", num[big][i]);
    }
    return 0;
}