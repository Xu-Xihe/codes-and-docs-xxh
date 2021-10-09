#include<stdio.h>
using namespace std;
int in[10000][10000],h,l,a,b,z,ha,la;//a=h;b=l;z=.out
int main(){
	scanf("%d%d",&h,&l);
	ha=h-1;
	la=l-1;
	a=0;
	while(true){
		b=0;
		while(true){
			scanf("%d",&in[a][b]);
			b++;
			if(b==l)break;
		}
		a++;
		if(a==h)break;
	}
	b=0;
	z=0;
	while(true){
		z+=in[0][b];
		b++;
		if(b==l)break;
	}
	b=0;
	while(true){
		z+=in[ha][b];
		b++;
		if(b==l)break;
	}
	a=1;
	while(true){
		z+=in[a][0]+in[a][la];
		a++;
		if(a<h)break;
	}
	printf("%d",z);
	
}
