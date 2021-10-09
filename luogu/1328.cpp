#include<stdio.h>
#include<iostream>
using namespace std;
int x[5][5]={
{1,0,2,2,0},
{2,1,0,2,0},
{0,2,1,0,2},
{0,0,2,1,2},
{2,2,0,0,1},};
int n,na[205],nb[205],ai=1,bi=1,A=0,B=0;
int main()
{
	scanf("%d%d%d",&n,&na[0],&nb[0]);
	while(true){
		scanf("%d",&na[ai]);
		ai++;
		if(ai>na[0])break;
	}
	while(true){
		scanf("%d",&nb[bi]);
		bi++;
		if(bi>nb[0])break;
	}
	ai=1;
	bi=1;
	while(n--){
		if(x[na[ai]][nb[bi]]==2) A++;
		if(x[na[ai]][nb[bi]]==0) B++;
		if(ai==na[0]) ai=1;
		else ai++;
		if(bi==nb[0]) bi=1;
		else bi++;
	}
	printf("%d %d",A,B);
}
