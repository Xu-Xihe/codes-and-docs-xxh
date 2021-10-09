#include<stdio.h>
using namespace std;
int a[100][100];
int ax,bx,m,n;
int main(){
	scanf("%d%d",&n,&m);
	ax=0;
	while(true){
		bx=0;
		while(true){
			scanf("%d",&a[ax][bx]);
			bx++;
			if(bx==m)break;
		}
		ax++;
		if(ax==n)break;
	}
	ax=bx=0;
	while(true){
		ax=0;
		while(true){
			printf("%d",a[ax][bx]);
			ax++;
			if(ax==n){
				printf("\n");
				break;
			}
			else printf(" ");
		}
		bx++;
		if(bx==m)break;
	} 
	return 0;
}
