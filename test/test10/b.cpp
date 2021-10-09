#include<cstdio>
#define maxe 100005
int len,end_point=1,start_point;
int ticket[maxe][3];
long long ans;
void del_ticket(int time){
    while (time-ticket[start_point][1]>45&&start_point<end_point)start_point++;
    return ;
}
int main(){
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        int b,c;
        bool a,d=0;
        scanf("%d%d%d",&a,&b,&c);
        if (a)
        {
           del_ticket(c);
           for(int find_point=start_point;find_point<end_point;find_point++){
               if(ticket[find_point][0]>=b&&ticket[find_point][2]){
                   d=true;
                   ticket[find_point][2]=false;
                   break;
               }
           }
           ans+=d?0:b;
        }
        else{
            ticket[end_point][0]=b;
            ticket[end_point][2]=true;
            ticket[end_point++][1]=c;
            ans+=b;
        }
        //printf("ans=%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}