#include<cstdio>
#include<cstring>
#define maxe 1000
using namespace std;
char in[maxe];
int ji[maxe],len;
void bian(int ia[],char in[],int&len){
    len=strlen(in);
    for (int i = 0; i < len; i++)
    {
        ia[i]=in[len-1-i]-1;
    }
}
void dfs(int in[]){
    
}
int main(){
    scanf("%s",in);
    bian(ji,in,len);
}