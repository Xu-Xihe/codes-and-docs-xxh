#include<stdio.h>
using namespace std;
int ina,inb[105];
char inc[105][105];
int main(){
	scanf("%d",&ina);
	for(int i=0;i<ina;i++){
		scanf("%d%s",&inb[i],inc[i]);
	}
	int big=0,ji;
	for(int i=0;i<ina;i++){
		if(inb[i]>big){
			big=inb[i];
			ji=i;
		}
	}
	printf("%s",inc[ji]);
	return 0;
}
