#include<cstdio>
#include<vector>
#include<algorithm>
#define maxe 200006
using namespace std;
vector<int>nodes[maxe];
int len,w[maxe];
long long ans,max_ans;
int main(){
    scanf("%d",&len);
    max_ans=0;
    for (int i = 1; i < len; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    for (int i = 1; i <= len; i++)
    {
        scanf("%d",&w[i]);
    }
    for (int now_id = 1; now_id <= len; now_id++)
    {
        long long sum=0,fi_max=-1,se_max=-1;
        for (int i = 0; i < nodes[now_id].size(); i++)
        {
            sum+=w[nodes[now_id][i]];
            if(w[nodes[now_id][i]]>=fi_max){
                int c=fi_max;
                fi_max=w[nodes[now_id][i]];
                se_max=c;
            }
            else if(w[nodes[now_id][i]]>se_max){
                se_max=w[nodes[now_id][i]];
            }
        }
        for (int i = 0; i < nodes[now_id].size(); i++)
        {
            ans+=(sum-w[nodes[now_id][i]])*w[nodes[now_id][i]];
            ans%=10007;
        }
        //long long lin=fi_max*se_max;
        //if(lin>max_ans){max_ans=lin;printf("now_id=%d %d %d\n",now_id,fi_max,se_max);}
        max_ans=se_max*fi_max>max_ans?se_max*fi_max:max_ans;
    }
    printf("%d %d\n",max_ans,ans);
    return 0;
}