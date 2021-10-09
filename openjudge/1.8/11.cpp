#include<stdio.h>
#include<string.h>
using namespace std;
int a[100][100],m,n,ax,bx;
int main(){
	scanf("%d%d",&n,&m);
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
	bx=0;
	while(true){
		ax=n-1;
		while(true){
			printf("%d",a[ax][bx]);
			ax--;
			if(ax<0){
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
