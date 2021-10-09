#include<cstdio>
#define maxe 100005
int len,ci,ans;
char people_name[maxe][15];
bool is_out[maxe];
int next_id(bool pep_turn ,bool le_or_re , int how_long){
    int ans=0;
    if (pep_turn)//out
    {
        if (le_or_re)//right
        {
            ans-=how_long;
        }
        else//left
        {
            ans+=how_long;
        }
    }
    else//in
    {
        if (le_or_re)//right
        {
            ans+=how_long;   
        }
        else//left
        {
            ans-=how_long;
        }
    }
    return ans;
}
void now_id(int & now){
    if (ans>=0)
    {
        ans%=len;   
    }
    else
    {
        while(ans<0)ans+=len;
    }
    return;
}
int main(){
    scanf("%d%d",&len,&ci);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%s",&is_out[i],people_name[i]);
    }
    for (int i = 0; i < ci; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ans+=next_id(is_out[ans],a,b);
        now_id(ans);
    }
    printf("%s\n",people_name[ans]);
    return 0;
}