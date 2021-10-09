#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6;
int num[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(num,0,sizeof num);
    for (int i=0 ;i< n ;i++){
        int a; scanf("%d",&a);
        int minVal = 1e9,pos = -1;
        for (int j = 0 ;j< m; j++)
            if (minVal > num[j]){
                minVal = num[j];
                pos = j;
            }
        num[pos] += a;
    }
    int maxNum = 0;
    for (int i= 0 ;i< m ;i++)
        maxNum = max(maxNum, num[i]);
    printf("%d\n",maxNum);
    return 0;
}
