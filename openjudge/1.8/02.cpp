#include<stdio.h>
using namespace std;
int n,i,j,hang,lie,h,l;
int main(){
	scanf("%d%d%d",&n,&i,&j);
	h=i;
	l=j;
	hang=1;
	while(true){//1
		printf("(%d,%d)",i,hang);
		if(hang==n){
			printf("\n");
			break;
		}
		else{
			hang++;
			printf(" ");
		}
	}
	lie=1;
	while(true){//2
		printf("(%d,%d)",lie,j);
		if(lie==n){
			printf("\n");
			break;
		}
		else{
			lie++;
			printf(" ");
		}
	}
	while(true){//3
		if(h==1||l==1){
			hang=h;
			lie=l;
			break;
		}
		else{
			h--;
			l--;
		}
	}
	while(true){//3
		printf("(%d,%d)",hang,lie);
		if(hang==n||lie==n){
			printf("\n");
			break;
		}
		else{
			hang++;
			lie++;
			printf(" ");
		}
	}
	while(true){//4
		if(j==1||j==n){
			hang=i;
			lie=j;
			break;	
		}
		else{
			i++;
			j--;
		}
	}
	while(true){//4
		if(hang<=0){
			printf("\n");
			break;
		}
		printf("(%d,%d)",hang,lie);
		if(lie==n){
			printf("\n");
			break;
		}
		else{
			hang--;
			lie++;
			printf(" ");
		}
	}
}