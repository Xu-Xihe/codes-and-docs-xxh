#include<cstdio>
#include<cstring>
using namespace std;
char in[25][25];
int W,H,px,py,ans;
int next_x[]={0,0,1,-1};
int next_y[]={1,-1,0,0};
void dfs(int nx,int ny){
    for (int i = 0; i < 4 ; i++)
    {
        int n_x=nx+next_x[i];
        int n_y=ny+next_y[i];
        if (in[n_x][n_y]=='.')
        {
            in[n_x][n_y]='+';
            dfs(n_x,n_y);
        }
    }
}
int main(){
    while(1)
    { 
        ans=0;
        memset(in,0,sizeof(in));
        scanf("%d%d",&W,&H);
        if (W==0&&H==0)
        {
            return 0;
        }
        for (int i = 1,a=0; i <= H; i++)
        {
            scanf("%s",in[i]+1);
            if (a==0)
            {
                for (int j = 1; j <= W; j++)
                {
                    if (in[i][j]=='@')
                    {
                        px=i;
                        py=j;
                        a=1;
                    }
                } 
            } 
        }
        dfs(px,py);
        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                //printf("%d %d %c\n",i,j,in[i][j]);
                if (in[i][j]=='+')
                {
                    ans++;
                }
            }
            //printf("%s\n",in[i]);
        }
        printf("%d\n",ans+1);
    }
}