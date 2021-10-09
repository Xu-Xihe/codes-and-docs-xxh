#include <cstdio>
#include <bitset>
#include <vector>
const int maxe = 600;
int n, m, e, ans, pot[maxe]; //一共有n个男生,m个女生,共e条边,pot[i]表示第i个女生属于的男生编号
std::bitset<maxe> vis;       //标记是否访问过(名花有主)
std::vector<int> con[maxe];  //以男生的角度记录这张图(因为要遍历男生找女生)
inline bool dfs(int now)
{
    for (auto i : con[now]) //遍历他有好感的所有女生
    {
        if (!vis[i]) //如果这个女生现在莫得npy
        {
            vis[i] = 1;                 //表示你就是我的了
            if (!pot[i] || dfs(pot[i])) //如果你原先没有npy或者前男友鱼塘里还有
            {
                pot[i] = now; //你现在彻底是我的了
                return true;  //表示我找到npy了(-_-)
            }
        }
    }
    return false; //我没有找到(T_T)
}
int main()
{
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        con[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        vis.reset(); //每次都重新分配
        if (dfs(i))  //如果现在的这个男生找到了npy,就又多了一对情侣
            ans++;
    }
    printf("%d", ans);
    return 0;
}