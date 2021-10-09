#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6;
char s[maxn];
int main(){
    scanf("%s",s);
    int lens = strlen(s);
    bool isNone = true;
    for (int i = 2; i<= 9 ;i++){
        int pre = 0;
        for (int j = 0 ;j<lens ;j++){
            pre = (pre*10 + s[j]-'0' )%i;
        }
        if (pre == 0) {
            printf("%d ",i);
            isNone = false;
        }
    }
    if (isNone)
        printf("none");
    return 0;
}

