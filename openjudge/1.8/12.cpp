#include<stdio.h>
#include<iostream>
//#include<time.h>
using namespace std;
char a[12][12],b[12][12];
int in,ax,z,bx;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&in);
	while(true){
		bx=0;
		while(true){
			cin>>a[ax][bx];
			//scanf("%c",&a[ax][bx]);
			if(a[ax][bx]==' ')bx--;
			bx++;
			if(bx==in)break;
		}
		ax++;
		if(ax==in)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			cin>>b[ax][bx];
			bx++;
			if(bx==in)break;
		}
		ax++;
		if(ax==in)break;
	}
	ax=z=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]==b[ax][bx])z++;
			bx++;
			if(bx==in)break;
		}
		if(z==(2*in)){
			printf("4");
			return 0;
		}
		ax++;
		if(ax==2)break;
	}
	ax=z=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]==b[bx][in-1-ax])z++;
			bx++;
			if(bx==in)break;
		}
		if(z==(2*in)){
			printf("1");
			return 0;
		}
		ax++;
		if(ax==2)break;
	} 
	ax=z=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]==b[in-1-bx][ax])z++;
			bx++;
			if(bx==in)break;
		}
		if(z==(2*in)){
			printf("2");
			return 0;
		}
		ax++;
		if(ax==2)break;
	} 
	ax=z=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]==b[in-1-ax][in-1-bx])z++;
			bx++;
			if(bx==in)break;
		}
		if(z==(2*in)){
			printf("3");
			return 0;
		}
		ax++;
		if(ax==2)break;
	} 
	//printf("%f\n",(double)clock()/CLOCKS_PER_SEC);
	printf("5");
	return 0;
}
