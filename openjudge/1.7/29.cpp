#include<stdio.h>
using namespace std;
char end;
int in[100],h;
void shuru(int a[100]){
	int i;
	char b;
	for(i=0;~scanf("%c",&b);i++){
		if(b=='-')i--;
		if(b>='0'&&b<='9')a[i]=b-'0';
		if(b=='X')a[i]=-1;
	}
	return ;
}
int main(){
	shuru(in);
	for(int i=0;i<9;i++)
		h+=in[i]*(i+1);
	h%=11;
	if(h==10)h=-1;
	if(h==in[9]){
		printf("Right");
		return 0;
	}
	else{
		printf("%d-",in[0]);
		for(int i=1;i<=3;i++)
			printf("%d",in[i]);
		printf("-");
		for(int i=4;i<9;i++)
			printf("%d",in[i]);
		if(h>=0)printf("-%d",h);
		else printf("-X");
		return 0;
	}
}
