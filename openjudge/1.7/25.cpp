#include<stdio.h>
#include<string.h>
using namespace std;
char in[10000][10000];
long long  len,big,small=1e6,bd,sd;
bool shuru(char in[1000]){
	for(int i=0;~scanf("%c",&in[i]);i++){
		if(in[i]==' '||in[i]==','){
			in[i]=0;
			return true;
		}
		if(in[i]=='\n'){
			in[i]=0;
			return false;
		}
	}
	return false; 
}
int main(){
	for(int i=0;shuru(in[i]);i++);
	for(int i=0;;i++){
		if(in[i][0]==0)break;
		int l=strlen(in[i]);
		if(l>big){
			big=l;
			bd=i;
		}
		if(l<small){
			small=l;
			sd=i;
		}
	}
	printf("%s\n",in[bd]);
	printf("%s",in[sd]);
	return 0;
}
