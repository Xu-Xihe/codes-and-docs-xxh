#include<cstdio>
#include<cstring>
using namespace std;
const int cp[3][3]={{1,2,3},{4,5,6},{7,8,'x'}};
struct bf
{
    int num[3][3];
};
struct xxx
{
    int x,y;
};

xxx last[3][3];
int main(){
    bf fir;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",&fir.num[i][j]);
        }
    }
    bfs();
}