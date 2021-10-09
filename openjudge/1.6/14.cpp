#include<stdio.h>
#define maxe 100000
using namespace std;
int out[maxe],in;
void jie(int a[maxe],int in){
	int big=0;
	for(int i=1;i<=in;i++){
		for(int j=0;j<=big;j++){
			a[j]*=i;
		}
		for(int j=0;j<=big;j++){
			int jin=a[j]/10;
			a[j]%=10;
			a[j+1]+=jin;
		}
		if(a[big+1])big++;
		while(a[big]/10>0){
			a[big+1]=a[big]/10;
			a[big]%=10;
			big++;
		}
	}
	return ;
}
int main(){
	out[0]=1;
	scanf("%d",&in);
	jie(out,in);
	int len;
	for(len=maxe-2;len>=0;len--)
		if(out[len]!=0)break;
	for(;len>=0;len--)
		printf("%d",out[len]);
	return 0;
}
