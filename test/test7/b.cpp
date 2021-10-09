#include<cstdio>
#include<vector>
#define maxe 200005
using namespace std;
int len,w[maxe],max_ans,ans;
vector<int>nodes[maxe];
int main(){
    scanf("%d",&len);
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
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j < nodes[i].size(); j++)
        {
            for (int z = 0; z < nodes[nodes[i][j]].size(); z++)
            {
                if(nodes[nodes[i][j]][z]>i){
                    int lin=w[i]*w[nodes[nodes[i][j]][z]];
                    //printf("%d->%d-%d\n",i,nodes[nodes[i][j]][z],lin);
                    max_ans=lin>max_ans?lin:max_ans;
                    ans+=lin;
                    ans%=10007;
                }
            }
        }
    }
    printf("%d %d\n",max_ans,(ans*2)%10007);
    return 0;
}