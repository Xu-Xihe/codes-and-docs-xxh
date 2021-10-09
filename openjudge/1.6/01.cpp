#include<stdio.h>
using namespace std;
int ina,inb[1000],inc,z;
int main(){
	scanf("%d",&ina);
	for(int i=0;i<ina;i++)scanf("%d",&inb[i]);
	scanf("%d",&inc);
	for(int i=0;i<ina;i++){
		if(inb[i]==inc)z++;
	}
	printf("%d",z);
	return 0;
}
