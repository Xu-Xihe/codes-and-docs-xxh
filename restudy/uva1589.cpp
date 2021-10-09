#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
int len,black_x,black_y;
struct chess
{
    int x,y,kind;//1-红帅 2-车 3-马 4-炮
};
std::vector<chess>chess_all;
bool can_fight[20][20],point[20][20];//0-空 1-可攻击 
const int horse_move[2][8]={{ 1, 1,-1,-1,2, 2,-2,-2},
                        {2,-2, 2,-2,1,-1, 1,-1}};
const int car_pao_move[2][4]={{0,0,1,-1},{1,-1,0,0}};
const int black_jiang_move[2][8]={{1,1,1,-1,-1,-1,0,0},{0,1,-1,0,1,-1,1,-1}};
bool if_out(int x,int y)
{
    return x>=1&&x<=9&&y>=1&&y<=10?0:1;
}
bool if_black_jiang_out(int x,int y)
{
    return x>=4&&x<=6&&y>=1&&y<=3?0:1;
}
void horse(int x,int y)
{
    int next_x,next_y;
    for (int i = 0; i < 8; i++)
    {
        next_x=x+horse_move[0][i];
        next_y=y+horse_move[1][i];
        if(point[next_x+horse_move[0][i]>0?-1:1][next_y+horse_move[1][i]>0?-1:1]||if_out(next_x,next_y))continue;
        can_fight[next_x][next_y]=1;
    }
    return;
}
void car_pao(int x,int y,bool kind)//1-car 0-pao
{
    int next_x,next_y;
    bool if_cross;
    for (int i = 0; i < 4; i++)
    {
        next_x=x;
        next_y=y;
        if_cross=kind;
        while(1)
        {
            next_x+=car_pao_move[0][i];
            next_y+=car_pao_move[1][i];
            if(if_out(next_x,next_y))break;
            if(point[next_x][next_y])
            {
                if(if_cross)
                {
                    can_fight[next_x][next_y]=1;
                    break;
                }
                else
                {
                    if_cross=1;
                    continue;
                }
            }
            can_fight[next_x][next_y]=1;
        }
    }
    return;
}
void jiang(int x,int y)
{
    int next_y=y;
    while(1)
    {
        next_y--;
        if(if_out(x,next_y))break;
        can_fight[x][next_y]=1;
        if(point[x][next_y])break;
    } 
    return;
}
int main()
{
    while(1)
    {
        while(chess_all.size())chess_all.pop_back();
        memset(can_fight,0,sizeof(can_fight));
        memset(point,0,sizeof(point));
        scanf("%d%d%d",&len,&black_y,&black_x);
        if(len==0&&black_x==0&&black_y==0)return 0;
        for (int  i = 0; i < len; i++)
        {
            int x,y;
            char a[10];
            chess push_in;
            scanf("%s%d%d",a,&y,&x);
            point[x][y]=1;
            push_in.kind=a[0]=='G'?1:a[0]=='R'?2:a[0]=='H'?3:4;
            push_in.x=x;
            push_in.y=y;
            chess_all.push_back(push_in);
        }
        for (int i = 0; i < len; i++)
        {
            if(chess_all[i].kind==1)jiang(chess_all[i].x,chess_all[i].y);
            if(chess_all[i].kind==2)car_pao(chess_all[i].x,chess_all[i].y,1);
            if(chess_all[i].kind==3)horse(chess_all[i].x,chess_all[i].y);
            if(chess_all[i].kind==4)car_pao(chess_all[i].x,chess_all[i].y,0);
        }
        int next_x,next_y;
        bool ans=0;
        /*for (int i = 1; i <= 10; i++)
        {
            for (int k = 1; k <= 9; k++)
            {
                printf("%d ",can_fight[k][i]);
            }
            printf("\n");
        }printf("\n\n");*/
        for (int i = 0; i < 8; i++)
        {
            next_x=black_x+black_jiang_move[0][i];
            next_y=black_y+black_jiang_move[1][i];
            //printf("%d %d %d\n",next_x,next_y,can_fight[next_x][next_y]);
            if(if_black_jiang_out(next_x,next_y))continue;
            if(can_fight[next_x][next_y]==0)
            {
                ans=1;
                break;
            }
        }
        printf("%s\n",ans==0?"YES":"NO");
    }
}