#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6;
int num[maxn],num2[maxn];
int main(){
    int totl = 0;
    memset(num,0,sizeof num);
    for (int i = 2;i < maxn ;i++){
        if (num[i] == 0){
            num2[totl++] = i;
            for (int j = i*2 ;j<maxn ;j+=i)
                num[j] = 1;
        }
    }
    int n;scanf("%d",&n);
    printf("%d\n",num2[n-1]);
    return 0;
}
