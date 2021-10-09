#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6;
int num[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0 ;i< n ;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    for (int i = 0 ;i< n; i++)
        if (i==0 || num[i]!=num[i-1])
            printf("%d ",num[i]);
    return 0;
}
