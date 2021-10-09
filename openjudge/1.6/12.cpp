#include<stdio.h>
#include<string.h>
using namespace std;
int in,jj,cang;
char out[40];
int main(){
	scanf("%d",&in);
	out[0]=1;
	while(in--){
		for(int i=0;i<40;i++){
			int z=out[i]*2;
			if(i!=0)out[i]=jj+z%10;
			else out[i]=z%10;
			jj=z/10;
		}
	}
	for(int i=40;i>=0;i--){
		if(out[i]!=0){
			cang=i;
			break;
		}
	}
	for(int i=cang;i>=0;i--)
		printf("%d",out[i]);
	return 0;
}
