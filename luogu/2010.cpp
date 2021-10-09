#include<cstdio>
using namespace std;
const int days[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int start,end,ans;
int huiwen(int month,int day)
{
    int a=0;
    a=day%10*1000;
    a+=day/10*100;
    a+=month%10*10;
    a+=month/10;
    return a;
}
bool tru(int year,int month,int day)
{
    int all = year * 10000 + month * 100 + day;
    if (all>end||all<start)
        return false;
    if (month != 2||(year%4==0&&year%100!=0)||year%400==0)
        return true;
    if(day<=28)
        return true;
    return false;
}
int main()
{
    scanf("%d%d",&start,&end);
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j<=days[i] ; j++)
        {
            int nyr = huiwen(i, j);
            if(tru(nyr,i,j))
                ans++;
            //printf("ce:  %d   %d  %d %d  %d  %d \n", i, j, nyr, start, end, ans);
        }
    }
    printf("%d",ans);
    return 0;
}