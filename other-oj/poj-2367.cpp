#include <cstdio>
#include <queue>
#include <vector>
using std::vector;
const int maxe = 109;                                             //最大节点个数
int len, in[maxe], cnt;                                           //len总节点数,in[i]第i号节点的入度,cnt已经遍历的节点个数
vector<int> next[maxe];                                           //邻接链表存图
std::priority_queue<int, vector<int>, std::greater<int> > running; //如无需按字典序输出,请改用queue;注意两个'>'中间有一个空格
int main()
{
    scanf("%d", &len);
    for (int i = 1; i <= len; i++)
    {
        int a;
        while (1)
        {
            scanf("%d", &a);
            if (!a)
                break;
            next[i].push_back(a);
            in[a]++; //每有一条指向节点的边,入度+1
        }
    }
    for (int i = 1; i <= len; i++)
    {
        if (in[i] == 0) //查找所有入度为0的节点
            running.push(i);
    }
    while (!running.empty())
    {
        int top = running.top();
        running.pop();
        printf("%d ", top);
        cnt++; //已经遍历的节点数+1
        int n = next[top].size();
        for (int i = 0; i < n; i++) //遍历所有出度,进行删边操作
        {
            int now = next[top][i];
            in[now]--;
            if (!in[now]) //如果删边后入度为0,则加入队列
                running.push(now);
        }
    }
    if (cnt != len) //如果以遍历节点数小于总节点数,说明有环
        printf("error\n");
    return 0;
}