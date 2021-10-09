#include<cstdio>
void read(int& x)
{
    x = 0;
    char c = getchar(), d = 0;
    while (c<'0'||c>'9')
    {
        d = c;
        c = getchar();
    }
    while(c>='0'&&c<='9')
    {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    if(d=='-')
        x = -x;
}
void wt(int x)
{
    if(x/10)
        wt(x / 10);
    putchar(x % 10 + '0');
}
void write(int x)
{
    if(x<0)
    {
        x = -x;
        putchar('-');
    }
    wt(x);
    putchar(' ');
}
int main()
{
    int len, a;
    read(len);
    while (len--)
    {
        read(a);
        write(a + 1);
    }
    return 0;
}