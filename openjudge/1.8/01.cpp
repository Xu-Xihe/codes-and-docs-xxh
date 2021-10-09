#include<stdio.h>
#include<algorithm> 
using namespace std;
int in[6][6],a=0,b=0,n,m;
int main(){
	while(true){
		b=0;
		while(true){
			scanf("%d",&in[a][b]);
			b++;
			if(b==5)break;
		}
		a++;
		if(a==5)break;
	}
	a=0;
	b=0;
	scanf("%d%d",&n,&m);
	n+=-1;
	m+=-1;
	while(true){
		swap(in[n][b],in[m][b]);
		b++;
		if(b==5)break;
	}
	while(true){
		b=0;
		while(true){
			printf("%d",in[a][b]);
			if(b==4)printf("\n");
			else printf(" ");
			b++;
			if(b==5)break;
		}
		a++;
		if(a==5)break;
	}
	return 0;
}
