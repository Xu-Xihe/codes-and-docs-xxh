#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4;
int num[maxn];
int main(){
    int totl = 0;
    memset(num,0,sizeof num);
    int n;
    scanf("%d",&n);
    int preNum;
    scanf("%d",&preNum);
    for (int i = 1 ;i< n; i++){
        int nowNum;
        scanf("%d",&nowNum);
        int ans = abs(nowNum-preNum);
        if (ans>=n || num[ans]==1) {
            printf("Not jolly\n");
            return 0;
        }
        num[ans] = 1;
        preNum = nowNum;
    }
    printf("Jolly\n");
    return 0;
}
