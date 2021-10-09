#include<stdio.h>
#include<string.h>
using namespace std;
char in[40];
int len;
void out(int a){
	for(int i=0;i<(len-a);i++)
			printf("%c",in[i]);
		return ;
}
int main(){
	scanf("%s",in);
	len=strlen(in);
	if(in[len-3]=='i'&&in[len-2]=='n'&&in[len-1]=='g'){
		out(3);
		return 0;
	}
	if(in[len-2]=='e'&&in[len-1]=='r'){
		out(2);
		return 0;
	}
	if(in[len-2]=='l'&&in[len-1]=='y'){
		out(2);
		return 0;
	}
	printf("%s",in);
	return 0;
}
