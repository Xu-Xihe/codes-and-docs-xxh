#include<cstdio>
#include<cstring>
#define maxe 1000
using namespace std;
int N,ji[maxe],ans;
void dfs(int line){
    for (int i = 0; i < N; i++)
    {
        bool a=true;
        for (int j = line-1; j >= 0; j--)
        {
            if (ji[j]==i||j-ji[j]==line-i||j+ji[j]==line+i)
            {
                a=false;
                break;
            }
        }
        /*printf("%d %d %d %d::::",line,i,a,ans);
        for (int j = 0; j < N; j++)
        {
            printf("%d ",ji[j]);
        }
        printf("\n");*/
        if (a)
        {
            if (line==N-1)
            {
                ans++;
            }
            else{
                ji[line]=i;
                dfs(line+1);
            }
        }
    }
    return ;
}
int main(){
    while (1)
    {
        scanf("%d",&N);
        if(N==0)return 0;
        ans=0;
        dfs(0);
        printf("%d\n",ans); 
    }
}