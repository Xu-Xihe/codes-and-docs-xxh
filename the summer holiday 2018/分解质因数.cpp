#include<stdio.h>
using namespace std;
int out[10000],in;
bool zhi;
bool fjzys(int in,int a[10000]){
	if(in==0){
		a[0]=0;
		a[1]=1;
		return true;
	}
	if(in==1){
		a[0]=1;
		a[1]=1;
		return true;
	}
	int z=0;
	for(int i=0;;){
		for(int j=2;j<=in;j++){
			if(in%j==0){
				if(j==in){
					if(z==0){
						a[0]=1;
						a[1]=in;
						return true;
					}
					else{
						a[i]=j;
						return false;
					}
				}
				else{
					a[i]=j;
					in/=j;
					j=2;
					i++;
					z=8;
				}
			}
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	printf("输入一个整数：");
	scanf("%d",&in);
	zhi=fjzys(in,out);
	int len=0;
	for(;;len++){
		if(out[len]==0)break;
	}
	for(int zl=0;zl<len;zl++){
		for(int i=1;i<len;i++){
			if(out[i-1]>out[i]){
				int lin=out[i];
				out[i]=out[i-1];
				out[i-1]=lin;
			}
		}
	}
	if(zhi)printf("%d是质数，它等于",in);
	else printf("%d是合数，它等于",in);
	for(int i=0;i<len-1;i++){
		printf("%d×",out[i]);
	}
	printf("%d",out[len-1]);
	return 0;
}
