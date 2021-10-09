#include<cstdio>
using namespace std;
int len,big=-1e9,small=1e9;
int main(){
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        int lin;
        scanf("%d",&lin);
        if (lin>big)
        {
            big=lin;
        }
        if (lin<small)
        {
            small=lin;
        }
    }
    printf("%d",big-small);
    return 0;
}