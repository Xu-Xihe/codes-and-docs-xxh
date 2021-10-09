#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stdlib.h>
using namespace std;
int close(char in){
    int a=in;
    a*=a;
    a*=rand()%2==0?1:-1;
    a+=27;
    a*=3;
    return a;
}
int main(){
    char a[100000];
    a[0]=0;
    a[1]='r';
    a[2]='m';
    a[3]=' ';
    int lin;
    printf("Please input your file name:");
    scanf("%s",a+4);
    freopen(a+4,"r",stdin);
    srand((unsigned)time(NULL));
    freopen("file.paxxh","w",stdout);
    int len=rand()%50000;
    printf("%s ",a+4);
    printf("%d %d ",rand(),rand());
    printf("%d ",len);
    char c;          
    for (int i = 0; i < len; i++)
    {
        printf("%d ",rand());
    }
    while (~scanf("%c",&c))
    {
        printf("%d ",close(c));
    }
    system(a);
    return 0;
}