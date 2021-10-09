#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define maxe 10000
int times,len,way;
bool is_check[maxe];
std::vector<int>ways[maxe];
struct node
{
    int next_id,value;
};
std::queue<node>running;
int main(){
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
        bool is_pep=0;
        int score,pep_num;
        scanf("%d%d",&pep_num,&score);
        while(!running.empty())running.pop();
        memset(is_check,0,sizeof(is_check));
        node first_in;
        first_in.next_id=pep_num;
        first_in.value=score;
        running.push(first_in);
        while (!running.empty())
        {
            int now_num=running.front().next_id,next_score=running.front().value-1;
            running.pop();
            //printf("-->%d->%d\n",now_num,next_score);
            is_check[now_num]=1;
            if(next_score==-1&&now_num==1)
            {
                is_pep=1;
                break;
            }
            for (int i = 0; i < ways[now_num].size(); i++)
            {
                if(next_score>=0)
                {
                    node next_node;
                    next_node.next_id=ways[now_num][i];
                    next_node.value=next_score;
                    running.push(next_node);
                }
            }
        }
        printf("%s\n",is_pep?"Yes":"No");
    }
    return 0;
}