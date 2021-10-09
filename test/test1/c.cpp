#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int wide, len, ans, now_q, start;
bool ji[10];
char pan[10][10];
bool none(int who,bool where[])
{
    return where[who]==false?true:false;
}
void dfs(int line)
{
    bool ji[10];
    if (line == wide)
        return;
    memset(ji,0,sizeof(ji));
    for (int i = 0; i < wide; i++)
    {
        if(pan[line][i]=='#'&&!ji[i]){
            
        }
    }
    
}
int main()
{
    while (~scanf("%d%d", &wide, &len))
    {
        ans = 0;
        now_q = len;
        memset(ji, 0, sizeof(ji));
        if (wide == -1 && len == -1)
            return 0;
        for (int i = 0; i < wide; i++)
        {
            scanf("%s", pan[i]);
        }
        dfs(0, ji);
        printf("%d\n", ans);
    }
    return 0;
}