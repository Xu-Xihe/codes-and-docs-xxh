#include<Windows.h>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int point,point_end,life=3;
struct node
{
    int x,y,m;
};
node per;
char out[16][22];
void print(){
    int end=5-life;
    printf("life: ");
    for (int i = 0; i < life; i++)
    {
        printf("%c ",'.');
    }
    for (int i = 0; i < end; i++)
    {
        printf("%c ",'?');
    }
    printf(" ");
    printf("point:%d\n\n",point);
    for (int i = 1; i < 16; i++)
    {
        for (int j = 1; j < 22; j++)
        {
            printf("%c",out[i][j]);
        }
        printf("\n");
    }
}
void line_made_s(int len,char in[],char fu){
    for (int j = 0; j < len; j++)
    {
        int aa=rand()%22;
        if(in[aa]=='='){
          in[aa]=fu;
        }
        else j--;
    }
}
void line_made(char in[]){
    for (int i = 0; i < 22; i++)
    {
        in[i]='=';
    }
    int lin=rand()%22;
    int a=lin%3;
    lin/=3;
    int b=lin%2;
    lin/=2;
    int c=lin;
    line_made_s(a,in,67);
    line_made_s(b,in,66);
    line_made_s(c,in,65);
}
void start_made(){
    for (int i = 0; i < 22; i++)
    {
        out[1][i]='=';
    }
    out[1][11]='>';
    for (int i = 2; i < 16; i++)
    {
        line_made(out[i]);
    }
}
int main(){
    start_made();
    print();
    return 0;
}