#include <cstdio>
#include <algorithm>
const int maxe = 1e5;
int root, tot, son[maxe][2], size[maxe], val[maxe], rnd[maxe], ll, rr, LL, RR;
#define Ls son[pos][0] //左儿子的编号
#define Rs son[pos][1] //右儿子的编号
inline int nnd(int x)  //声明一个新的节点并分配priority值
{
    size[++tot] = 1;
    val[tot] = x; //注意，维护有序队列时，应把x替换成tot，想清楚要维护的是什么
    rnd[tot] = rand();
    return tot;
}
inline void upd(int pos) //更新节点size大小
{
    size[pos] = size[Rs] + size[Ls] + 1;
}
inline void spv(int pos, int key, int &l, int &r) //按照权值分裂,pos当前节点编号,key分裂值,&l左侧挂载位置,&r右侧挂载位置
{
    if (pos == 0) //没有叶子节点,结束递归
    {
        l = r = 0; //没有叶子节点,结束递归,并将挂载点赋值0(空)
        return;
    }
    if (val[pos] <= key) //如果当前节点小于等于key,则将左子树(都小于当前节点,所以都小于key值)和当前节点挂在左侧,继续分裂右子树
    {
        l = pos;             //挂在上次传递的挂载点位置
        spv(Rs, key, Rs, r); //递归分裂右子树,因为右子树中所有值均大于当前节点,因此如果仍有小于key值的应挂在当前节点的右儿子的地方
    }
    else //如果当前节点大于key,则将右子树(都大于当前节点,所以都大于key值)和当前节点挂在右侧,继续分裂左子树
    {
        r = pos;             //挂在上次传递的挂载点位置
        spv(Ls, key, l, Ls); //递归分裂左子树,因为左子树中所有值均小于当前节点,因此如果仍有大于key值的应挂在当前节点的左儿子的地方
    }
    upd(pos); //更新节点size大小(因为分裂开后,子树大小有改变)
}
inline void spn(int pos, int key, int &l, int &r) //按照节点个数分裂,pos当前节点编号,key分裂值,&l左侧挂载位置,&r右侧挂载位置
{
    if (pos == 0) //没有叶子节点,结束递归,并将挂载点赋值0(空)
    {
        l = r = 0;
        return;
    }
    if (size[Ls] + 1 <= key) //如果左子树和当前节点个数之和小于等于key,则挂在左侧,继续在右子树中选key-size[Ls]-1个加入左侧
    {
        l = pos;                            //挂在上次传递的挂载点位置
        spn(Rs, key - size[Ls] - 1, Rs, r); //递归分裂右子树,因为已经在左侧又挂了size[Ls]+1个节点,所以要在右子树中再选key-size[Ls]-1个即可
    }
    else //如果左子树和当前节点个数之和大于key,不满足条件,继续在右子树查找size合适的子树
    {
        r = pos;             //挂在上次传递的挂载点位置
        spn(Ls, key, l, Ls); //递归分裂左子树,因为并没有在左侧挂任何节点,因此key不改变
    }
    upd(pos); //更新节点size大小(因为分裂开后,子树大小有改变)
}
inline int tog(int l, int r) //合并两棵树,l左侧树的根节点,r右侧树的根节点;递归思想
{
    if (l == 0 || r == 0) //如果任意一个树是空的,剩余的树的根节点就是挂载点
        return l + r;
    if (rnd[l] < rnd[r]) //优先级定义,可以随便写
    {
        son[l][1] = tog(son[l][1], r); //右侧树挂载左侧树的右侧
        upd(l);                        //更新左侧树根节点的信息
        return l;                      //返回新树的根节点
    }
    son[r][0] = tog(l, son[r][0]); //左侧树挂载右侧树的左侧
    upd(r);                        //更新右侧树根节点的信息
    return r;                      //返回新树的根节点
}
inline void ins(int v)
{
    spv(root, v, ll, rr);            //按照v分割成根节点为ll和rr两棵子树
    root = tog(tog(ll, nnd(v)), rr); //先合并ll和新加入的节点,再和rr合并,然后更新总树的根节点
}
inline void del(int val)
{
    spv(root, val, ll, rr);        //按照v分割成根节点为ll和rr两棵子树
    spn(ll, size[ll] - 1, ll, LL); //再在左侧分割出1个节点挂在右侧
    root = tog(ll, rr);            //合并新ll和rr,不合并第二次分裂的右侧1个节点,即删除,然后更新总树的根节点
}
inline int ordv(int v)
{
    spv(root, v - 1, ll, rr); //将所有小于v的数分割
    int r = size[ll];         //记录根节点size,即所有小于v的节点的数量,后续合并时可能变化
    root = tog(ll, rr);       //合并分裂开的两棵树
    return r + 1;             //返回注意+1
}
inline int ordn(int k)
{
    spn(root, k, ll, rr);        //分裂出前k个节点
    spn(ll, k - 1, ll, RR);      //再分裂出前k-1个节点,这样右侧就有一个排名为k的节点,其下标为RR
    root = tog(tog(ll, RR), rr); //合并分裂开的两棵树
    return val[RR];              //返回编号为RR的节点的权值
}
inline int fit(int v)
{
    spv(root, v - 1, ll, rr);      //先分裂出所有小于v的节点
    spn(ll, size[ll] - 1, ll, RR); //再在小于v的节点中分裂出最大的一个,因为ll是根节点,size[ll]即为小于v的节点数量
    root = tog(tog(ll, RR), rr);   //合并分裂开的ll,前缀和rr
    return val[RR];                //返回前驱的值
}
inline int back(int v)
{
    spv(root, v, ll, rr);        //先分裂出所有小于等于v的节点
    spn(rr, 1, LL, rr);          //再在大于v的节点中分裂出最小的一个
    root = tog(tog(ll, LL), rr); //合并分裂开的ll,后缀和rr
    return val[LL];              //返回后缀的值
}
int main()
{
    int len, a, b;
    scanf("%d", &len);
    while (len--)
    {
        scanf("%d%d", &a, &b);
        if (a == 1)
            ins(b);
        if (a == 2)
            del(b);
        if (a == 3)
            printf("%d\n", ordv(b));
        if (a == 4)
            printf("%d\n", ordn(b));
        if (a == 5)
            printf("%d\n", fit(b));
        if (a == 6)
            printf("%d\n", back(b));
    }
    return 0;
}