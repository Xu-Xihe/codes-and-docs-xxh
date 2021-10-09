#include<stdio.h>
using namespace std;
int len,ji[200005][200005],x,y;
int main(){
	scanf("%d",&len);
	for(int z=1;z<=len;z++){
		int a=0,b=0,g=0,f=0;
	 	scanf("%d%d%d%d",&a,&b,&g,&f);
	 	for(int i=b;i<=b+f;i++){
	 		for(int j=a;j<=a+g;j++){
	 			ji[i][j]=z;
			}
		}
	}
	scanf("%d%d",&x,&y);
	int lin=ji[x][y];
	if(lin==0)printf("-1");
	else printf("%d",lin);
	return 0;
}
