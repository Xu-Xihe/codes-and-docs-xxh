#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <ctime>
#define random(x) rand()%(x)
using namespace std;
const int maxn = 1010;
char s[maxn][maxn];
int whereAns[maxn],totl;
int visited[maxn];
int proid[maxn];
int main(){
    int m;scanf("%d",&m);
    freopen("��Ŀ.txt", "r", stdin); 
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    totl = 0;
    while (gets(s[totl++]));
    for (int i = 0 ;i< totl ;i++){
        int lens = strlen(s[i]);
        for (int j = 0 ;j< lens ;j++){
            if (s[i][j]=='&'){
                whereAns[i]=j+1; 
                s[i][j]=0;
                break;
            }
        }
    }
    memset(visited,0,sizeof visited); 
   freopen("测试题目.txt", "w", stdout); 
    for (int i = 0 ;i<m&&i<totl; i++){
        int id = random(totl);
        while (visited[id]) id = random(totl);
        proid[i]=id;
        visited[id] = 1;
        printf("题目%d: %s\n",i+1,s[id]);
    }
    freopen("测试答案.txt", "w", stdout); 
    for (int i = 0 ;i<m&&i<totl; i++){
        int id = proid[i] ;
        printf("答案%d: %s\n",i+1,s[id]+whereAns[id]);
    }
    return 0;
}
