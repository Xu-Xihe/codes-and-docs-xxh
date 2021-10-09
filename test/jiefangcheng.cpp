#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<iostream>
#define maxe 10000
using namespace std;
struct stg_1
{
    bool front;//1:+,2:-
    queue<char>stg;
};
char in[maxe],unknown;
stg_1 stg[5];//1:left_1,2;left_0,3:right_1,4:right_0
int const_1,const_2;//const_2 is the X's num
bool check(char in[],char&wen){
    wen=0;
    int a[5];
    memset(a,0,sizeof(a));
    int len=strlen(in);
    for ( int i = 0; i < len; i++)
    {
        if(in[i]>='A'&&in[i]<='Z')in[i]+='a'-'A';
        if(in[i]=='='){
            if(a[0]==0)a[0]++;
            else return false;
        }
        else if(in[i]>='a'&&in[i]<='z'){
            if (wen==0)
            {
                wen=in[i];
            }
            else if(wen!=in[i])return false;
        }
        else if(in[i]<='0'&&in[i]>='9'&&in[i]!='/'&&in[i]!='*'&&in[i]!='+'&&in[i]!='-')return false;
    }
    return true;
}
void chuli_1(char in[]){

}
int main(){
    while(1){
        printf("Please input your linear equation in one unknown here:");
        scanf("%s",in);
        if(check(in,unknown)==0)printf("\nYou input has sonething wrong,please try again.\n\n");
        else break;
    }
    
}
