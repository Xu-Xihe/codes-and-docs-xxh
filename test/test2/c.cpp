#include<cstdio>
using namespace std;
int len;
int in[2000000];
int main(){
    while (~scanf("%d",&len))
    {
        for(int i=0;i<len;i++)
            scanf("%d",&in[i]);
        printf("Yes\n");
    }
    return 0;
}