#include <cstdio>
#include <vector>
#include <cstring>
const int maxe = 3e4 + 9;
int n, tot;
struct node //每个节点储存节点编号和节点上的字符
{
    int id;
    char val;
    bool tag;
};
std::vector<node> next[maxe]; //储存每个节点的儿子,便于查找
inline void ins(char *in)     //本来应该是dfs的,只不过优化为循环了
{
    int now = 0, len = strlen(in); //标记当前节点的编号,字符串的长度
    for (int i = 0; i < len; i++)
    {
        int ci = next[now].size(); //遍历子节点
        bool is = 0;               //记录是否找到可以用的链
        for (int j = 0; j < ci; j++)
        {
            if (next[now][j].val == in[i])
            {
                if (i == len - 1) //如果是字符串结尾就打tag
                    next[now][j].tag = 1;
                is = 1;
                now = next[now][j].id; //跳转到这个儿子，继续ins
                break;
            }
        }
        if (!is) //如果没有匹配的节点,就要新建一个
        {
            next[now].push_back(node{++tot, in[i], i == len - 1 ? true : false});
            now = tot; //跳转到新建的节点
        }
    }
}
inline bool find(char *in) //本来应该是dfs的,只不过优化为循环了
{
    int now = 0, len = strlen(in); //标记当前节点的编号,字符串的长度
    for (int i = 0; i < len; i++)
    {
        int ci = next[now].size(); //遍历子节点
        bool is = 0;               //记录是否找到可以用的链
        for (int j = 0; j < ci; j++)
        {
            if (next[now][j].val == in[i])
            {
                is = 1;           //标记找到了
                if (i == len - 1) //如果是结尾,则判断是否有tag(若没有,就是字典中某个字符串的前缀)
                    is = next[now][j].tag;
                now = next[now][j].id;
                break;
            }
        }
        if (!is) //如果没找到合适的子节点,说明树中没有这个字符串
            return false;
        if (i == len - 1) //如果全部匹配,则字典中有所查询的字符串
            return true;
    }
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        char type[10], in[1000];
        scanf("%s %[^\n]", type, in);
        if (type[0] == 'a')
            ins(in);
        else
            printf("%s\n", find(in) ? "yes" : "no");
    }
    return 0;
}