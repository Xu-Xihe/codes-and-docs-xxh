#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int maxn = 100010;
int num[maxn],n;
bool visited[maxn];
int main (){
    //for (int i = 1; i<=1 ;i++){
    //    string fileDir = "../数据/C/game";
    //    string fileName = to_string(i);
    //    string hz1 = ".in";
    //    string hz2 = ".out";
    //    freopen((fileDir + fileName + hz1).c_str(),"r",stdin);
    //    freopen((fileDir + fileName + hz2).c_str(),"w",stdout);

    while (~scanf("%d",&n)){
        for (int i = 1 ;i<= n ;i++)
            scanf("%d",&num[i]);
        int maxNum = 0;
        bool hasOne = false,hasTwo = false;
        bool onlyTwo = true;
        memset(visited,0,sizeof visited);
        for (int i = 1 ;i<=n ;i++){
            if (num[i] == i)
                hasOne = true;
            if (num[num[i]] == i)
                hasTwo = true;
            int cnt = 0;
            int Id = i;
            while (visited[Id]==false){
                visited[Id] = true;
                cnt++;
                Id = num[Id];
            }
            if (cnt % 2)
                onlyTwo = false;
            maxNum = max(maxNum,cnt);
        }
        if ( (hasTwo) & (onlyTwo) ||hasOne)
            printf("Yes\n");
        else
            printf("No\n");
    }
    //}
    return 0;
}
