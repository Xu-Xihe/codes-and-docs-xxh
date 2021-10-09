#include<cstdio>
using namespace std;
int l,w;
char a,b;
void bian(int a,char b){
    for (int i = 0; i < a; i++)
    {
        printf("%c",b);
    }
}
int main(){
    scanf("%d %d",&l,&w);
    scanf(" %c",&a);
    bool lin;
    scanf("%d",&lin);
    if(lin){
        b=a;
    }
    else b=' ';
    bian(w,a);
    printf("\n");
    for (int i = 0; i < l-2; i++)
    {
        printf("%c",a);
        for (int i = 0; i < w-2; i++)
        {
            printf("%c",b);
        }
        printf("%c\n",a);
    }
    bian(w,a);
    return 0;
}