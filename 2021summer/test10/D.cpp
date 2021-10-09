#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <string.h>

const int maxe = 1e6 + 9;
int tot1, tot2, n, m;
struct node
{
    int id, tag;
    char val;
};
std::vector<node> son1[maxe];
std::vector<node> son2[maxe];
char inss[maxe];
inline void ins(char *in, int &tot, std::vector<node> next[maxe])
{
    int now = 0, len = strlen(in);
    for (int i = 0; i < len; i++)
    {
        int ci = next[now].size();
        bool is = 0;
        for (int j = 0; j < ci; j++)
        {
            if (next[now][j].val == in[i])
            {
                next[now][j].tag += 1;
                is = 1;
                now = next[now][j].id;
                break;
            }
        }
        if (!is)
        {
            next[now].push_back(node{++tot, 1, in[i]});
            now = tot;
        }
    }
}
inline int find(char *in, int len, int tot, std::vector<node> next[maxe])
{
    int now = 0;
    for (int i = 0; i < len; i++)
    {
        int ci = next[now].size();
        bool is = 0;
        for (int j = 0; j < ci; j++)
        {
            if (next[now][j].val == in[i])
            {
                is = 1;
                if (i == len - 1)
                {
                    //printf("ceshi  %d  %d  %d  %c\n", now, j, next[now][j].id, next[now][j].val);
                    return next[now][j].tag;
                }
                now = next[now][j].id;
                break;
            }
        }
        if (!is)
            return 0;
    }
}
inline int check(char *a)
{
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '*')
            return i;
    }
}
void show(int tot, std::vector<node> out[maxe])
{
    printf("\n");
    for (int i = 0; i <= tot; i++)
    {
        printf("\n%d:  ", i);
        for (auto j : out[i])
            printf("%d %c %d  --    ", j.id, j.val, j.tag);
    }
    printf("\n");
}
inline void strrev(char *in)
{
    int len = strlen(in);
    for (int i = 0, j =len-1; i<j; i++,j--)
    {
        std::swap(in[i], in[j]);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", inss);
        ins(inss, tot1, son1);
        strrev(inss);
        ins(inss, tot2, son2);
    }
    //show(tot1, son1);
    //show(tot2, son2);
    while (m--)
    {
        scanf("%s", inss);
        int lin = strlen(inss), ck = check(inss);
        //printf("%s  %d  %d\n", inss, lin, ck);
        if (!ck)
        {
            strrev(inss);
            printf("%d\n", find(inss, lin - 1, tot2, son2));
        }
        else
        {
            printf("%d\n", find(inss, lin - 1, tot1, son1));
        }
    }
    return 0;
}