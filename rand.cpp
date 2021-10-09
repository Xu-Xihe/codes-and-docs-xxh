#include<cstdio>
#include<ctime>
#include<stdlib.h>
const int maxe = 10;
int main()
{
    int in;
    scanf("%d",&in);
    srand(time(NULL));
    printf("choose:the %d one\n",rand()%in+1);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%d  ", rand() % maxe + 1);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}