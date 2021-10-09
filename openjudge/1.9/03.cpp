#include<stdio.h>
using namespace std;
int ina[10],inb[10],inc[10];
int main(){
	for(int i=0;i<7;i++){
		scanf("%d%d",&ina[i],&inb[i]);
		inc[i]=ina[i]+inb[i]-8;
	}
	int big=0,ji=-1;
	for(int i=0;i<7;i++){
		if(inc[i]>big){
			big=inc[i];
			ji=i;
		}
	}
	if(ji<0)printf("0");
	else printf("%d",ji+1);
	return 0;
}
