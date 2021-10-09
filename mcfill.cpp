#include <cstdio>
struct pair
{
    int fir, sec;
    void con()
    {
        if (fir > sec)
        {
            int c = fir;
            fir = sec;
            sec = c;
        }
    }
} a, b, c;
int main()
{
    printf("The first one: ");
    scanf("%d%d%d", &a.fir, &b.fir, &c.fir);
    printf("\nThe second one: ");
    scanf("%d%d%d", &a.sec, &b.sec, &c.sec);
    a.con();
    b.con();
    c.con();
    for (int i = a.fir; i <= a.sec; i++)
    {
        for (int j = b.fir; j <= b.sec; j++)
        {
            for (int z = c.fir; z <= c.sec; z++)
            {
                for (int y = 0; y < 6; y++)
                {
                    printf("replaceitem block %d %d %d container.%d tnt 64\n", i, j, z, y);
                }
            }
        }
    }
}