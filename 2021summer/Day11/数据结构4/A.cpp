#include <cstdio>
struct node
{
    int next[60];//我们直接开出全部字符范围,然后按照下标存储
    bool tag; //0~29  30~59
} nodes[3000000];
int root = 1, tot = 1;
inline void ins(char *in)
{
    int pos = root, val;//val就是让你省一点代码
    for (; *in; ++in) //这玩意和 for(int i = 0;i < len;i++)一个意思
    {
        val = (*in) >= 'A' && (*in) <= 'Z' ? (*in) - 'A' : (*in) - 'a' + 30;//找到相对应的下标
        if (!nodes[pos].next[val])//没有这个节点
            nodes[pos].next[val] = ++tot;
        pos = nodes[pos].next[val];//跳转到下一个,继续插入
    }
    nodes[pos].tag = true;//结尾打tag
}
inline bool find(char *in)
{
    int pos = root, val;
    for (; *in; ++in)
    {
        val = (*in) >= 'A' && (*in) <= 'Z' ? (*in) - 'A' : (*in) - 'a' + 30;
        if (!nodes[pos].next[val])
            return false;
        pos = nodes[pos].next[val];
    }
    return nodes[pos].tag>0?true:false;
}
int len;
char ord[10], name[500];
int main()
{
    scanf("%d", &len);
    while (len--)
    {
        scanf("%s %[^\n]", ord, name);
        if (ord[2] == 'd')
            ins(name);
        else
            printf("%s\n", find(name) ? "yes" : "no");
    }
    return 0;
}