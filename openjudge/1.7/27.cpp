#include<stdio.h>
#include<string.h>
using namespace std;
char in[1000];
void zhao(int&a){
	while(a<strlen(in)){
		if(in[a]==' '){
			a--;
			return ;
		}
		a++;
	}
	a=strlen(in)-1;
}
void out(int qi,int zhong){
	for(int i=zhong;i>=qi;i--){
		//printf("\ni=%d\n",i);
		printf("%c",in[i]);
	}
}
void shuru(char in[1000]){
	for(int i=0;~scanf("%c",&in[i]);i++){
		if(in[i]=='\n'){
			in[i]=0;
			break;
		}
	}
	return ;
}
int main(){
	shuru(in);
	int len=strlen(in);
	for(int i=0;i<len;i++){
		if(in[i]==' ')printf(" ");
		else{
			int lin=i;
			zhao(i);
			//printf("i=%d\n",lin);
			out(lin,i);
		}
	}
	return 0;
}
