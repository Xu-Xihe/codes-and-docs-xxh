#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#define maxe 10000
int len,way,times;
bool is_check[maxe];
struct node
{
    int next_id,value;
};
std::vector<int>ways[maxe];
std::queue<node>running;
int main()
{
    scanf("%d%d%d",&len,&way,&times);
    for (int i = 0; i < way; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ways[a].push_back(b);
        ways[b].push_back(a);
    }
    while (times--)
    {
        int pep_num,score;
        scanf("%d%d",&pep_num,&score);
        memset(is_check,0,sizeof(is_check));
        while(!running.empty())running.pop();
        node pu_in;
        pu_in.next_id=pep_num;
        pu_in.value=0;
        running.push(pu_in);
        bool ans=false;
        while (!running.empty())
        {
            int top_id=running.front().next_id,top_value=running.front().value;
            running.pop();
            printf("-->%d--%d\n",top_id,top_value)
            if(top_id==1&&top_value==score)
            {
                ans=true;
                break;
            }
            if(top_value>score)continue;
            for(int i=0;i<ways[top_id].size();i++)
            {
                if(!is_check[ways[top_id][i]])
                {
                    pu_in.next_id=ways[top_id][i];
                    pu_in.value=top_value+1;
                    is_check[ways[top_id][i]]=true;
                }
            }
        }
        printf("%s\n",ans?"Yes":"No");
    }
    return 0;
}