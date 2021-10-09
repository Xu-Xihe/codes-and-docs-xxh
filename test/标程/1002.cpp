#include <cstdio>
using namespace std;
int num[110];
int main (){
    int n;scanf("%d",&n);
    for (int i = 0 ;i< n;i++)
        scanf("%d",&num[i]);
    for (int i=n-1;i>=0 ;i--)
        printf("%d ",num[i]);
    return 0;
}

