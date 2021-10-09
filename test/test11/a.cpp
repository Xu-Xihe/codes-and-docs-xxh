#include<cstdio>
#include<cstring>
int ji[20];
void dfs(int deep,int biggest,int lest){
    if(biggest==0&&lest!=0)return;  
    if(lest-biggest<0||lest==0){
        printf("%d",ji[0]);
        //int b=ji[0];
        for (int i = 1; i < deep; i++)
        {
            printf("+%d",ji[i]);
            //b+=ji[i];
        }
        if(lest>0)printf("+%d",lest);
        //printf("   ==%d",b+=lest);
        printf("\n");
        return;
    }
    for (int i = biggest;i > 0; i--)
    {
        ji[deep]=i;
        dfs(deep+1,i-1,lest-i);   
    }
}
int main(){
    for (int i = 30; i > 10; i--)
    {
        ji[0]=i;
        dfs(1,i-1,66-i);
    }
    return 0;
}