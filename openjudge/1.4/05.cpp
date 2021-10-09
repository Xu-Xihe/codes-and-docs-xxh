#include<stdio.h>
using namespace std;
int main()
{
	long int x,y;
    scanf("%ld%ld",&x,&y);
    if(x>y)    printf(">");
    if(x<y)    printf("<");
    if(x==y)    printf("=");
}
