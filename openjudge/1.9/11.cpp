#include<stdio.h>
#include<string.h>
using namespace std;
char in[1004];
int len,chang;
int main(){
	scanf("%d%s",&chang,in);
	len=strlen(in);
	for(int i=0;i<len;i++){
		char lin=in[i];
		int z=0;
		for(int j=0;j<chang;j++){
			int nx=i+j;
			if(nx>=len){
				printf("No");
				return 0;
			}
			if(in[nx]==lin)z++;
		}
		if(z==chang){
			printf("%c",lin);
			return 0;
		}
	}
	printf("No");
	return 0;
}
