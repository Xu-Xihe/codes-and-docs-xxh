#include<cstdio>
#define maxe 500005
int tree[maxe],len,ci;
int lowbit(int a){
    return a&-a;
}
void add(int node_id,int num){
    while (node_id<=len)
    {
        tree[node_id]+=num;
        node_id+=lowbit(node_id);
    }
}
int find(int e_id){
    int ans=0;
    for(;e_id > 0;e_id-=lowbit(e_id)){
        ans+=tree[e_id];
    }
    return ans;
}
int main(){
    scanf("%d%d",&len,&ci);
    for (int i = 1; i <= len; i++)
    {
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    while (ci--)
    {
        int lin,a,b;
        scanf("%d",&lin);
        if(lin==1){
            int c;
            scanf("%d%d%d",&a,&b,&c);
            for(int i=a;i<=b;i++)add(i,c);
        }
        else{
            scanf("%d",&a);
            printf("%d\n",find(a)-find(a-1));
        }
    }
    return 0;
}