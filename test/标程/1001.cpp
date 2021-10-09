#include <cstdio>
using namespace std;
int main (){
    double n,k;
    scanf("%lf%lf",&n,&k);
    int yearNum = -1;
    double money = 200;
    for (int i = 0 ;i< 20; i++){
        if (money<=(i+1)*n){
            yearNum = i+1;
            break;
        }
        money *= (1+k/100);
    }
    if (yearNum == -1) printf("Impossible\n");
    else printf("%d\n",yearNum);
    return 0;
}
