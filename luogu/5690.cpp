#include <cstdio>
const int date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
          end[] = {1, 2, 3, 5, 7, 8, 0};
int ans, month, day;
bool accept(int month, int day)
{
    if (month == 0 || day == 0)
        return false;
    if (month <= 12 && day <= date[month])
    {
        return true;
    }
    return false;
}
int main()
{
    scanf("%d-%d", &month, &day);
    if (accept(month, day))
    {
        printf("0");
        return 0;
    }
    if (month > 12 || month == 0)
    {
        ans++;
        bool a = month / 10 == 1 || month == 0 ? true : false;
        month %= 10;
        for (int i = 0; !a && i < 7; i++)
        {
            if (month == end[i])
            {
                a = true;
            }
        }
        if (a)
            month = 12;
        else
            month %= 11;
    }
    if (day > date[month] || day == 0)
    {
        ans++;
    }
    printf("%d", ans);
    return 0;
}